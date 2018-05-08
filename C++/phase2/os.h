// os.h
#include "Assembler.h"
#include "VirtualMachine.h"
#include <fstream>
#include <string>
#include <queue>
#include <list>

#ifndef OS_H
#define OS_H

class PCB
{
    friend class OS;
    
    int pc, sr, sp, base, limit, clk;
    int reg[4];
    string process_name;
    fstream * object_file; 
    fstream * input_file; 
    fstream * output_file;
    fstream * stack_file;
    int io_completion; //keeps track of the time at which the I/O operation for this process is complete
    int waiting_time; //keeps track of time spent in ready queue
    int cpu_time, turnaround_time, io_time, largest_stack_size,
        context_switch_ticks, idle_ticks, jobs_cpu_time, total_number_of_processes;
};

class OS {
    private:
        Assembler as;
        VirtualMachine vm;
        list<PCB *> jobs;
        queue<PCB *> readyQ, waitQ;
        PCB * running;
        
    public: 
        OS();
        void initialize();
        void save_current_state();
        void start_execution();
        void load(fstream &);
        void context_switch();
        void read();
        void write();
};

class SR_bits {
    public:
        unsigned CARRY:1;
        unsigned GREATER:1;
    	unsigned EQUAL:1;
    	unsigned LESS:1;
    	unsigned OVERFLOW:1;
    	unsigned STATUS:3;
    	unsigned IO:2;
    	unsigned RESERVED:6;
};
        
union StatRegister {
    int i;
    SR_bits bit_format;
};



#endif