/******************************************************************
*CSE 460 - Spring 2016 - Phase I: Assembler & Virtual Machine
*Programmer: Adam Salcido, Kyle Lee
*File name: Assembler.cpp
*Date: 4/6/16
*Description: This program takes in instructions from '.s' files
* into Assembler, converts it to object code, sends it over to Virtual
* Machine where the correct operations are calculated and stored in
* an .out file that stores the correct value from the assembly code, additionally
* the amount of clock ticks the program takes. It it also important
* to note that the .in file allows for a value to be assigned to a 
* register in order for the code to execute the set of instructions. 
******************************************************************/
// os.cpp

#include "Assembler.h"
#include "VirtualMachine.h"
#include "os.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// extern const int os_time_slice = 15;

main(int argc, char *argv[])
{
    OS operating_system;
    operating_system.initialize();
}


/*

void os::load()
{
    string filename = argv[1];
    size_t period = filename.find('.');
    string base = filename.substr(0, period);
    string object_file = base.append(".o");
    
    fstream assembly, object;
    assembly.open(filename.c_str(), ios::in);
    object.open(object_file.c_str(), ios::out);
    as.read_file(assembly, object);
    
    assembly.close();
    object.close();
    
    object.open(object_file.c_str(), ios::in);
    string inputs = base.replace(base.find('.'), string::npos, ".in");
    string outputs = base.replace(base.find('.'), string::npos, ".out");
    fstream data_in, data_out;
    data_in.open(inputs.c_str(), ios::in);
    data_out.open(outputs.c_str(), ios::out);
    
    vm.read_file(object, data_in, data_out);
    
    object.close();
    data_in.close();
    data_out.close();
    
}


void os::run() {
    do {
        vm.swap();
        vm.run(os_time_slice);
    } while (vm.active());
    
    vm.print_info();
}
*/