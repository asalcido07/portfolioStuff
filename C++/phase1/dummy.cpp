#include <iostream>
#include <fstream>
#include "Assembler.h"

using namespace std;

main()
{
    fstream input, output; //object_code;
    Assembler as;
    //VirtualMachine vm;
    
    input.open("prog.s", ios::in);
    output.open("prog.o", ios::out);
    //object_code.open("derp.o"), ios::in); // Added fstream object named object_code to read in derp.o 
    
    as.read_file(input, output);
    //vm.read_file(object_code); // Passes derp.o to vm method read_file
    input.close();
    output.close();
    //object_code();
}