/******************************************************************
*CSE 460 - Spring 2016 - Phase I: Assembler & Virtual Machine
*Programmer: Adam Salcido, Kyle Lee
*File name: Assembler.cpp
*Date: 4/6/16
*Description: The assembler takes an assembly file (.s) and converts
*each instruction into integers that will be placed in the object file
*(.o). The Assembler will check for out-of-bounds values for
*ADDR and CONST, as well as for any invalid opcodes and register 
*values. 
******************************************************************/
// Virtual Machine.cpp

// Assembler.cpp

#include "Assembler.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
                        // Variables are initialized in the constructor
Assembler::Assembler()
{
    instruct["load"] = 0;
	instruct["loadi"] = 0;	
	instruct["store"] = 1; 
	instruct["add"] = 2;
	instruct["addi"] = 2;
	instruct["addc"] = 3;
	instruct["addci"] = 3;
	instruct["sub"] = 4;
	instruct["subi"] = 4;
	instruct["subc"] = 5;
	instruct["subci"] = 5;
	instruct["and"] = 6;
	instruct["andi"] = 6;
	instruct["xor"] = 7;
	instruct["xori"] = 7;
	instruct["compl"] = 8;
	instruct["shl"] = 9;
	instruct["shla"] = 10;
	instruct["shr"] = 11;
	instruct["shra"] = 12;
	instruct["compr"] = 13;
	instruct["compri"] = 13;
	instruct["getstat"] = 14;
	instruct["putstat"] = 15;
	instruct["jump"] = 16;
	instruct["jumpl"] = 17;
	instruct["jumpe"] = 18;
	instruct["jumpg"] = 19;
	instruct["call"] = 20;
	instruct["return"] = 21;
	instruct["read"] = 22;
	instruct["write"] = 23;
	instruct["halt"] = 24;
	instruct["noop"] = 25;
} // Assembler

// Read file takes in the instructions from the prog.s file, and stores them to 
// the appropriate private members of the Assembler class
// From their we assign RD, RS, CONS, I,  and RD based on the opcode
// Additionally, we assign it a format based on integer value called 'format'
void Assembler::read_file(fstream &input, fstream &output)  
{                                                           
    string line, oper_code;                                 
    map<string, int>::iterator it;
    int i;
    
    getline(input, line);
    //Ignores comments 
    line = line.substr(0, line.find('!'));
    
    while (!input.eof()) {
        rd = -1;
        rs = -1;
        constant = -129;
        address = -1;
        int i = 0; // i is assigned 0, added at 4:06
        
        //Checks if empty line (other than comments)
        if (line.empty()) {
            getline(input, line);
            continue;
        }
        
        istringstream str(line.c_str());
        str >> oper_code;
        cout << "oper_code: " << oper_code << "\n";
        
        //Checks opcode for validity
        for (it = instruct.begin(); it != instruct.end(); it++) {
            if (oper_code == it->first) {
                opcode = it->second;
                cout << "opcode: " << opcode << "\n";
                break;
            }
            
            if (it == instruct.end()) {
                cout << "Invalid opcode! Assembly halted." << "\n";
                exit(1);
            }
        }
        
        if ((oper_code == "load") || (oper_code == "loadi") || (oper_code == "store") || (oper_code == "addi") || ( oper_code == "addci") 
			|| (oper_code == "subi") || (oper_code == "subci") || (oper_code == "andi") || (oper_code == "xori") || (oper_code == "compri")) {
				if ((oper_code == "load") || (oper_code == "store")) {
					str >> rd >> address; // If oper_code equals any of these cases store the values from str into rd and address
					format = 0; // Assigns value for switch statement in write_object_code()
				} else {
					str >> rd >> constant; // If oper_code equals any of these cases store the values from str into rd and constant
					format = 1;			   // Assigned format 1 for switch statement in write_object_code()
				}
				//test code
				
				if ((oper_code.find('i') != string::npos) || (oper_code == "store")) {	// Searches for i, if 'i' is found in search variable,
					i = 1;													// assign it to 1, else assign it to 0.
				} 
			/*	else {
					i = 0; // No longer necessary since i initialized to zero at top of function
				}*/
				
		} else if ((oper_code == "add") || (oper_code == "addc") || (oper_code == "sub") || (oper_code == "subc") || (oper_code == "and") || (oper_code == "xor") || (oper_code == "compr")) {
			str >> rd >> rs;
			format = 2;
		} else if ((oper_code == "compl") || (oper_code == "shl") || (oper_code == "shla") || (oper_code  == "shr") || (oper_code == "shra") 
				|| (oper_code == "getstat") || (oper_code == "putstat") || (oper_code == "read") || (oper_code == "write")) {
			str >> rd;
			format = 3;
		} else if ((oper_code == "jump") || (oper_code == "jumpl") || (oper_code == "jumpe") || (oper_code == "jumpg") || (oper_code == "call")) {
			str >> address;
			i = 1;
			format = 4;
		} else if ((oper_code == "return") || (oper_code == "halt") || (oper_code == "noop")) {
			cout << "";
			cout << "I'm in halt, return, and noop conditional statement\n";
			format = 5;
		} else {
			cout << "Opcode doesn't exist.\n";
			exit(0);
		}
		
		check_instructions();
		write_object_code(output, i); 
		getline(input, line);
		line = line.substr(0, line.find('!'));
        
    }
}

//Checks instructions for valid ADDR, CONST, and register values
void Assembler::check_instructions() 
{
    /*
    if (((0 <= rd) && (rd <= 3)) && ((0 <= rs) && (rs <= 3))) {
        	if (((address >= 0)&&(address < 256))||((constant >= -128)&&(constant < 128))) {
            		cout << "Instructions are good";
            } else {
            	cout << "Instructions are bad";
            	exit(0);
            }
    } else {
        cout << "RD and/or RS are outside the range of the register numbers.";
        exit(0);
    }
    */
    switch (format) {
        
        case 0: 
            if ((0 <= rd) && (rd <= 3)) {
                if ((0 <= address) && (address < 256)) {
                    cout << "Instruction is valid.\n";
                } else {
                    cout << "Address is out of bounds.\n";
                    exit(0);
                }
            } else {
                cout << "RD is out of bands.\n";
                exit(0);
            }
            break;
        
        case 1: 
            if ((0 <= rd) && (rd <= 3)) {
                if ((-128 <= constant) && (constant < 128)) {
                    cout << "Instruction is valid.\n";
                } else {
                    cout << "Constant is out of bounds.\n";
                    exit(0);
                }
            } else {
                cout << "RD is out of bands.\n";
                exit(0);
            }
            break; 
            
        case 2: 
            if ((0 <= rd) && (rd <= 3)) {
                if ((0 <= rs) && (rs <= 3)) {
                    cout << "Instruction is valid.\n";
                } else {
                    cout << "RS is out of bounds.\n";
                    exit(0);
                }
            } else {
                cout << "RD is out of bands.\n";
                exit(0);
            }
            break;
        
        case 3: 
            if ((0 <= rd) && (rd <= 3)) {
                cout << "Instruction is valid.\n";
            } else {
                cout << "RD is out of bands.\n"; 
                exit(0);
            }
            break;
            
        case 4:
            if ((0 <= address) && (address < 256)) {
                cout << "Instruction is valid.\n";
            } else {
                cout << "Address is out of bounds.\n";
                exit(0);
            }
            break;
    }              
} // check_instructions

// write_object takes in the output from read_file, stores the value in converted and shifts it 11 bits.
// From our variable 'format' we determine which case converted will be applied to for our object code.
// From there, the bits are shift accordingly.
void Assembler::write_object_code(fstream &output, int i)  
{                                                   
    int converted;
    converted = opcode << 11;
    
    switch (format) {
        case 0:
            converted += rd << 9;
            cout << "0) Converted: " << converted << "\n";
            cout << "i: " << i << "\n";
            converted += i << 8;
            cout << "0) Converted: " << converted << "\n";
            converted += address;
            cout << "0) Converted: " << converted << "\n\n";
            break;
            
        case 1: 
            converted += rd << 9;
            cout << "1) Converted: " << converted << "\n";
            cout << "i: " << i << "\n";
            converted += i << 8;
            cout << "1) Converted: " << converted << "\n";
            sample.negative = constant;
            cout << sample.negative << "\n";
            cout << sample.positive << "\n";
            converted += sample.positive;
            cout << sample.positive << "\n";
            cout << "1) Converted: " << converted << "\n\n";
            break;
            
        case 2: 
            converted += rd << 9;
            cout << "2) Converted: " << converted << "\n";
            cout << "i: " << i << "\n";
            converted += i << 8;
            cout << "2) Converted: " << converted << "\n";
            converted += rs << 6;
            cout << "2) Converted: " << converted << "\n\n";
            break;
        
        case 3:
            cout << "3) Converted: " << converted << "\n";
            cout << "i: " << i << "\n";
            converted += rd << 9;
            cout << "3) Converted: " << converted << "\n\n";
            break;
            
        case 4: 
            cout << "4) Converted: " << converted << "\n";
            cout << "i: " << i << "\n";
            converted += i << 8; 
            cout << "4) Converted: " << converted << "\n";
            converted += address; 
            cout << "4) Converted: " << converted << "\n\n";
            break;
    }
    output << converted << "\n";    
} // write_object_code