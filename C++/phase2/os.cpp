/******************************************************************
*CSE 460 - Spring 2016 - Phase II: Assembler & Virtual Machine
*Programmer: Adam Salcido, Kyle Lee
*File name: os.cpp
*Date: 6/13/16
*Description: The OS manages all of the PCB queues that represent all of 
* the processes that are currently loaded into memory. When certain 
* statuses (such as a time slice or I/O operation) are reached in the 
* virtual machine, the virtual machine returns control to the OS, and 
* the OS performs a context switch, reorganizing the queues so that the 
* processes are in the correct queue, depending on the type of return status.
******************************************************************/
// os.cpp

#include "Assembler.h"
#include "VirtualMachine.h"
#include "os.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdint.h>

using namespace std;

int memory_continuation = 0;    //keeps track of where to write next program to memory when loading programs into memory
OS::OS() { }

void OS::initialize() {         // Defines necessary variables to copy .s files into progs, stores them assembly_file, and creates appropriate .o files
    cout << "This verifies that I'm actually in the initialize function of OS\n";
    string assembly_file;
    ifstream progs;
    fstream dot_s_file, dot_o_file, dot_in_file, dot_out_file, dot_st_file;
    
    system("ls *.s > progs");
    progs.open("progs");
    
    if (!progs.is_open()) {
        cout << "There was a problem generating progs file.\n";
        return;
    }
    
    progs >> assembly_file;                         // Takes in string values of progs input file, stores in assembly_file
    cout << "Before the while loop, the contents of assembly_file is: " << assembly_file << endl;
    while (!progs.eof()) {                          // While not end of progs, open .s file, create .o file
        
        dot_s_file.open(assembly_file.c_str(), ios::in);
        size_t period = assembly_file.find('.');
        string no_suffix = assembly_file.substr(0, period);
        string object_filename = no_suffix;
        string input_filename = no_suffix;
        string output_filename = no_suffix; 
        string stack_filename = no_suffix;
        
        //Associates file streams with their corresponding files
        object_filename.append(".o");
        input_filename.append(".in");
        output_filename.append(".out");
        stack_filename.append(".st");    //Note: input and stack file should exist before program is assembled
        dot_o_file.open(object_filename.c_str(), ios::out);
        dot_in_file.open(input_filename.c_str(), ios::in);
        dot_out_file.open(output_filename.c_str(), ios::out);
        dot_st_file.open(stack_filename.c_str(), ios::in | ios::out);
        
        as.read_file(dot_s_file, dot_o_file);    // Pass in input/output file stream and call Assembler's read_file method
        dot_s_file.close();
        dot_o_file.close();
        
        //Initializes values in the PCB
        PCB * p = new PCB;
        p->process_name = no_suffix;
        p->object_file = &dot_o_file;
        p->input_file = &dot_in_file;
        p->output_file = &dot_out_file;
        p->stack_file = &dot_st_file;
        p->base = memory_continuation;  // where program begins in memory
        p->pc = p->base;
        p->sr = 0;
        p->sp = 256;
        for (int i = 0; i < 4; i++)
            p->reg[i] = 0;
        dot_o_file.open(object_filename.c_str(), ios::in);
        load(dot_o_file);            // loads object files into memory
        p->limit = memory_continuation - p->base; // size of program
        
        jobs.push_back(p);
        readyQ.push(p);
        
        cout << "The assembly_file string is currently: " << assembly_file << endl;
        progs >> assembly_file;
    }
    
    //after all programs are loaded into memory, use a variable to store the 
    //total amount of memory being used (needed for stack)
    vm.total_memory_used = memory_continuation;
    start_execution();

    //loop that controls context switching and process execution
    //Need to set loop to terminate when every process has terminated
    while (true) {
        vm.run();
        context_switch();
        //no more processes left
        if (readyQ.empty() && waitQ.empty())
            break;
        start_execution();
        //cout << "You're in the while loop of os.cpp!!!" << endl;
    }
    
    //close all open files associated with all the PCBs after all processes have 
    //finished executing
    for (list<PCB *>::iterator it = jobs.begin(); it != jobs.end(); it++) {
        ((*it)->input_file)->close();
        ((*it)->object_file)->close();
        ((*it)->output_file)->close();
        ((*it)->stack_file)->close();
    }
    //when all processes have finished executing, deallocate all dynamic memory
    while (!jobs.empty()) {
        delete jobs.front();
        jobs.pop_front();
    }
   
} // initialize


//save the current program's state into its PCB so that it can be swapped out from "running"
void OS::save_current_state()
{
    running->clk = vm.clk;
    running->pc = vm.pc;
    running->sr = vm.sr;
    
    //if stack is not empty (sp < 256), write the stack to stack file
    running->sp = vm.sp;
    (running->stack_file)->seekp(0);
    //write contents of stack to stack file
    while (running->sp < 256) 
        *(running->stack_file) << vm.mem[(running->sp)++];
    
    for (int i = 0; i < 4; i++)
        running->reg[i] = vm.r[i];
        
}
//loads a process's information (such as registers) into the CPU for execution 
void OS::start_execution() 
{
    running = readyQ.front(); // Stores value of readyQ to running pointer
    readyQ.pop();               // Queue is popped
    running->waiting_time += (vm.clk - running->clk); //updates waiting time
    running->clk = vm.clk; //updates PCB clock with time it enters running state
    vm.base = running->base;
    vm.pc = running->pc;
    vm.limit = running->limit;
    vm.sr = running->sr;
    vm.sp = running->sp;
    
    //reset "return status" status bits to zero; they will be set to a value in the VM when the 
    //appropriate status is encountered
    for (int i = 5; i < 8; i++)
        vm.sr &= (0 << i);
    
    for (int i = 0; i < 4; i++)
        vm.r[i] = running->reg[i];
}

//loads programs into memory during OS initialization
void OS::load(fstream &object_file)
{
    object_file >> vm.mem[memory_continuation++];
    while (!object_file.eof()) {
        object_file >> vm.mem[memory_continuation++];
    }
}


//handles context switching
void OS::context_switch()
{
    vm.clk += 5;
    
    PCB *pcb;
    
    //saves state of running process to its PCB
    save_current_state();
    
    //checks for processes in wait queue that have finished their I/O operations
    while (waitQ.size()) {
        pcb = waitQ.front();
        
        
        if (pcb->io_completion > vm.clk)
            break;
        readyQ.push(pcb);
        pcb->clk = vm.clk; //stamps PCB clock with the time that it entered the ready queue
        waitQ.pop();
        pcb->io_time += (vm.clk - pcb->clk); //adds any incurred I/O time to that process's PCB
    }
    
    StatRegister sr;
    sr.i = running->sr;
        
    switch (sr.bit_format.STATUS) {
        case 0: 
            readyQ.push(running);
            break;
                
        case 1: 
            cout << "CPU time: " << pcb->cpu_time << "\n" <<
        	"Waiting time: " << pcb->waiting_time << "\n" <<
        	"Turnaround time: " << (pcb->cpu_time + pcb->waiting_time + pcb->io_time) / 1000.0 << "\n" <<
        	"I/O time: " << pcb->io_time << "\n" <<
        	"Largest stack size: " << pcb->largest_stack_size << "\n";
        	//jobs_cpu_time += pcb->cpu_time;
        	break;
            
        case 2:
            cout << "Out-of-bound reference error\n";
            break; 
            
        case 3: 
            cout << "Stack overflow error\n";
            break;
            
        case 4: 
            cout << "Stack underflow error\n";
            break; 
                
        case 5: 
            cout << "Invalid Opcode error\n";
            break;
            
        //read
        case 6:
            *(running->input_file) >> running->reg[sr.bit_format.IO]; // Takes in value from fstream input and place it in a register
            waitQ.push(running);
            running->clk = vm.clk;  //stamps current CPU time to PCB to indicate when that process entered the wait queue
            running->io_completion = vm.clk + 28;
            break;
            
        //write
        case 7: 
            cout << "Writing to file..." << endl;
            	
            *(running->output_file) << running->reg[sr.bit_format.IO] << endl;	// Writes out value inside register to fstream 
            waitQ.push(running);
            running->clk = vm.clk;  //stamps current CPU time to PCB to indicate when that process entered the wait queue
            running->io_completion = vm.clk + 28;
            break;
        }
        
       
} // swap





