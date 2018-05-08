
// Virtual Machine.cpp

#include "VirtualMachine.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <cstdint> // Added this on
#include <vector>

using namespace std;

instruction ins;

VirtualMachine::VirtualMachine()
{
    r = vector <int> (REG_FILE_SIZE);
    mem = vector <int> (MEM_SIZE);
    pc = ir = sr = base = clk = 0; // Changed limit to 10, which is the size of the instructions
    flag = true;
    sp = 256;
	
	instructions[0] = &VirtualMachine::load_i; // Key values are like previous map
	instructions[1] = &VirtualMachine::store;
	instructions[2] = &VirtualMachine::add_i;
	instructions[3] = &VirtualMachine::add_c_i;
	instructions[4] = &VirtualMachine::sub_i;
	instructions[5] = &VirtualMachine::sub_c_i;
	instructions[6] = &VirtualMachine::and_i;
	instructions[7] = &VirtualMachine::xor_i;
	instructions[8] = &VirtualMachine::compl_;
	instructions[9] = &VirtualMachine::shl;
	instructions[10] = &VirtualMachine::shla;
	instructions[11] = &VirtualMachine::shr;
	instructions[12] = &VirtualMachine::shra;
	instructions[13] = &VirtualMachine::compr_i;
	instructions[14] = &VirtualMachine::get_stat;
	instructions[15] = &VirtualMachine::put_stat;
	instructions[16] = &VirtualMachine::jump;
	instructions[17] = &VirtualMachine::jump_l;
	instructions[18] = &VirtualMachine::jump_e;
	instructions[19] = &VirtualMachine::jump_g;
    instructions[20] = &VirtualMachine::call;
    instructions[21] = &VirtualMachine::return_;
    instructions[22] = &VirtualMachine::read;
    instructions[23] = &VirtualMachine::write;
    instructions[24] = &VirtualMachine::halt;
    instructions[25] = &VirtualMachine::noop;
} // VirtualMachine

void VirtualMachine::read_file(fstream &object_code, fstream &input_file, fstream &output_file)
{
	//Sets pointers to input/output file stream addresses (added 4/24 10:19 AM)
	input = &input_file;
	output = &output_file;
	
	/*//Loads instructions into memory
	int i;
	for (i = base; i < mem.size() and !object_code.eof(); i++) 
		object_code >> mem[i];*/
	
	limit = i; // Added this so limit is now the size of object code instructions
	
	while (flag) {
		cout << "Hey, I'm in the while loop right now!!!" << endl;
		ir = mem[pc++]; // Fetch is done here
		decode();
	}
	
	(*output) << "Total clock ticks: " << clk << endl;
	
} // read_file

void VirtualMachine::decode()
{
	ins.i = ir; 
	
	cout << "OP: " << ins.f1.OP << "\n";
	
	if ((ins.f1.OP == 22) || (ins.f1.OP == 23)) {
		clk += 28;
	} else if (((ins.f2.OP == 0) && (ins.f2.I == 0)) || (ins.f1.OP == 1) || (ins.f1.OP == 20) || (ins.f1.OP == 21)) {
		clk += 4; 
	} else {
		clk++;
	} // These conditions dont' take care of every case, have to look over
	  // Modified code to take care of every case possible at 12:24 AM  
	  // Conditions modified 4/24, 10:41 AM
	
	(this->*instructions[int(ins.f1.OP)])(); // Execute instruction	
	
	cout << "R0: " << r[0] << " R1: " << r[1] << " R2: " << r[2] << " R3: " << r[3] << " SR: " << sr << "\n";
	
} // decode
								// load_i assigns a constant or address to a register based on the i bit
void VirtualMachine::load_i()
{
    if (ins.f1.I == 1) {		
    	r[ins.f3.RD] = ins.f3.CONST;
    } else {
    	r[ins.f2.RD] = mem[ins.f2.ADDR];
    	cout << "Executing load instruction..." << endl;
    } 
} // load_i
								// Store assigns the value from an address to memory
void VirtualMachine::store()
{
    mem[ins.f2.ADDR] = r[ins.f2.RD];
    cout << "Storing the value " << mem[ins.f2.ADDR] << endl;
} // store
							// Addition is done based on i bit, in which either CONST or RS will be added with RD, carry will be set accordingly
void VirtualMachine::add_i()
{
	if (ins.f1.I == 1) {
		overflow_detect(r[ins.f3.RD], ins.f3.CONST, ins.f3.OP);
		r[ins.f3.RD] += ins.f3.CONST;
		cout << "Executing ADD_I instruction..." << endl;
		cout << "New value in RD after addition is: " << r[ins.f3.RD] << endl;
		
	} else {
    	overflow_detect(r[ins.f1.RD], r[ins.f1.RS], ins.f3.OP);
    	r[ins.f1.RD] += r[ins.f1.RS];
	}
	
	//Set carry bit
	if ((r[ins.f1.RD] & 1) == 0) {
		sr |= 1;
	} else {
		sr &= 0 << 1;
	}
} // add_i

void VirtualMachine::add_c_i() // Not sure how to do this one, needs carry
{
	int carry = sr & 1;
	
	if (ins.f1.I == 1) {
		overflow_detect(r[ins.f3.RD], ins.f3.CONST+carry, ins.f3.OP);
		r[ins.f3.RD] = r[ins.f3.RD] + ins.f3.CONST + carry; // CARRY hasn't been defined yet, changed at 6:34 PM
	} else {
		overflow_detect(r[ins.f1.RD], r[ins.f1.RS] + carry, ins.f1.OP);
		r[ins.f1.RD] = r[ins.f1.RD] + r[ins.f1.RS] + carry; // changed at 6:34 PM
	}
	
	if ((r[ins.f1.RD] & 1) == 0) {
		sr |= 1;
	} else {
		sr &= 0 << 1;
	}
} // add_c_i
								// Subtraction is done based on i bit, in which either CONST or RS will be added with RD, carry will be set accordingly
void VirtualMachine::sub_i()
{
    if (ins.f3.I == 1) {
    	r[ins.f3.RD] = r[ins.f3.RD] - ins.f3.CONST; // Have to account for CARRY, changed at 6:36 PM
    } else {
    	r[ins.f1.RD] = r[ins.f1.RD] - r[ins.f1.RS]; // have to set carry, changed at 6:36 PM
    }
    // running->sr.carry = (running->r[running->ir.rd] & 1);
    if (r[ins.f1.RD] & 1) {
    	sr |= 1; 
    } else {
		sr &= 0 << 1;
	}
} // sub_i

void VirtualMachine::sub_c_i()
{
    int carry = sr & 1;
    
    if (ins.f1.I == 1) {
    	r[ins.f3.RD] = r[ins.f3.RD] - ins.f3.CONST - carry; // Have to set carry
	} else {
		r[ins.f1.RD] = r[ins.f1.RD] - r[ins.f1.RS] - carry;
	}
	
	if (r[ins.f1.RD] & 1) {
    	sr |= 1;
	} else {
		sr &= 0 << 1;
	}
} // sub_c_i
								// Does and based on i bit and the value is assigned to the RD
void VirtualMachine::and_i()
{
    if (ins.f1.I == 1) {
    	r[ins.f3.RD] &= ins.f3.CONST;
    } else {
    	r[ins.f1.RD] &= r[ins.f1.RS];
    }
} // and_i
								// Does exclusive or based on i bit and the value is assigned to the RD
void VirtualMachine::xor_i()
{
    if (ins.f1.I == 1) {
    	r[ins.f3.RD] ^= ins.f3.CONST;
    } else {
    	r[ins.f1.RD] ^= r[ins.f1.RS];
    }
} // xor_i
								// Takes the complement of the value inside the RD
void VirtualMachine::compl_()
{
    r[ins.f1.RD] = ~r[ins.f1.RD];
} // compl_
							// Shifts value left 1 bit inside RD
void VirtualMachine::shl()
{
	bool bit = (r[ins.f1.RD] >> 15) & 1;
	if (bit) {
		sr |= 1;
	} else {
		sr &= 0 << 1;
	}
	
    r[ins.f1.RD] = r[ins.f1.RD] << 1; // Need to set carry
} // shl

void VirtualMachine::shla()
{
    bool bit = (r[ins.f1.RD] >> 15) & 1; // Added this at 6:22 PM
	if (bit) {
		sr |= 1;
	} else {
		sr &= 0 << 1;
	}
    r[ins.f1.RD] = (int16_t(r[ins.f1.RD])) << 1; // Added at 6:42 PM
} // shla 
							// Shifts value right 1 bit inside RD
void VirtualMachine::shr()
{
	bool bit = (r[ins.f1.RD] >> 0) & 1; // Added this at 6:20 PM, changed to look at the 0 bit
	
	cout << "Bit: " << bit << "\n";
	
	if (bit) {
		sr |= 1; 
	} else {
		sr &= 0 << 1;
	}
    r[ins.f1.RD] = r[ins.f1.RD] >> 1; // Need to set carry bit
} // shr

void VirtualMachine::shra()
{
	bool bit = (r[ins.f1.RD] >> 0) & 1; // Added this at 6:22 PM, Changed to look at the 0 bit 
	if (bit) {
		sr |= 1; 
	} else {
		sr &= 0 << 1;
	}
	r[ins.f1.RD] = (int16_t(r[ins.f1.RD])) >> 1; // Added at 6:43 PM
}  // shra
								// Based on i, RD will be either compared with RS or CONST and the equal, less,
void VirtualMachine::compr_i()	//  or greater bit is set and the others reset
{
    if (ins.f1.I == 1) {
    	if (r[ins.f3.RD] < ins.f3.CONST) {
    		sr |= 1 << 3;
    		sr &= ~(1 << 2);
    		sr &= ~(1 << 1);
    	} else if (r[ins.f3.RD] == ins.f3.CONST) {
    		sr |= 1 << 2;
    		sr &= ~(1 << 3);
    		sr &= ~(1 << 1);
    	} else if (r[ins.f3.RD] > ins.f3.CONST) {
    		sr |= 1 << 1;
    		sr &= ~(1 << 3);
    		sr &= ~(1 << 2);
    	}
    		
    } else {
    	if (r[ins.f1.RD] < r[ins.f1.RS]) {
    		sr |= 1 << 3;
    		sr &= ~(1 << 2);
    		sr &= ~(1 << 1);
    	} else if (r[ins.f1.RD] == r[ins.f1.RS]) {
    		sr |= 1 << 2;
    		sr &= ~(1 << 3);
    		sr &= ~(1 << 1);
    	} else if (r[ins.f1.RD] > r[ins.f1.RS]) {
    		sr |= 1 << 1;
    		sr &= ~(1 << 3);
    		sr &= ~(1 << 2);	
    	}
    }
} // compr_i
								// RD is assigned the value from sr 
void VirtualMachine::get_stat()
{
    r[ins.f1.RD] = sr;
} // get_stat
								// sr is assigned the value from the RD
void VirtualMachine::put_stat()
{
    sr = r[ins.f1.RD];
} // put_stat
							// pc is assigned an address
void VirtualMachine::jump()
{
    pc = ins.f2.ADDR;
} // jump
								// Checks to see if less bit is set, if so pc is assigned an address, otherwise do nothing
void VirtualMachine::jump_l()
{
    if ((sr >> 3) & 1) {
    	pc = ins.f2.ADDR;
    }
    
} // jump_l
								// Checks to see if equal bit is set, if so pc is assigned an address, otherwise do nothing
void VirtualMachine::jump_e()
{
    if ((sr >> 2) & 1) {
    	pc = ins.f2.ADDR;
    }
} // jump_e
								// Checks to see if greater bit is set, if so pc is assigned an address, otherwise do nothing
void VirtualMachine::jump_g()		
{
	if ((sr >> 1) & 1)  {
    	pc = ins.f2.ADDR;
    }
} // jump_g
							// Stores address, puts registers, sr and pc in memory, sp is decremented accordingly
void VirtualMachine::call()
{
	cout << "Inside call function..." << endl;
    
    if (sp >= limit+6) {
    	for (int i = 0; i < 4; i++) 
    		mem[--sp] = r[i];
    	
    	mem[--sp] = sr;
    	mem[--sp] = pc;
    	pc = ins.f2.ADDR;
    } else {
    	cout << "Stack overflow! Program aborted.\n";
    	exit(0);
    }
} // call
								// pc, rs, and registers are restored and sp is incremented accordingly
void VirtualMachine::return_()
{
	cout << "Restoring PC and SR..." << endl;
	pc = mem[sp++];
	sr = mem[sp++];
	for (int i = 3; i != -1; i--) {
		r[i] = mem[sp++];
		cout << "Restoring all registers..." << endl;
	}
} // return_

void VirtualMachine::read()
{
	cout << "Reading from file..." << endl;
	(*input) >> r[ins.f2.RD]; // Takes in value from fstream input and place it in a register
} // read

void VirtualMachine::write()
{
	cout << "Writing to file..." << endl;
	//sign extends result if sign bit indicates a negative number
	int total_bits = sizeof(int) * 8;
	if (r[ins.f2.RD] & (1 << 15)) {
		for (int i = 16; i < total_bits; i++) 
			r[ins.f2.RD] |= (1 << i);
	}
	(*output) << r[ins.f2.RD] << endl;	// Writes out value inside register to fstream output
} // write

void VirtualMachine::halt()
{
    flag = false;	// Assigned false to make the program stop running in the while loop of read_file
    cout << "HALT\n";
} // halt
							// Nothing is done, besides print out a cout statement
void VirtualMachine::noop()
{
    cout << "NOOP\n";
} // noop

void VirtualMachine::overflow_detect(int first, int second, int OP) 
{
	//Overflow detection for addition
	if ((OP == 2) || (OP == 3)) {
		//Tests if two negative numbers make a positive number
		if (int16_t(first) < 0 && int16_t(second) < 0 && !(int16_t(first+second) & (1 << 15)))
			sr |= 0x10;
		//Tests if two positive numbers make a negative number
		else if (int16_t(first) > 0 && int16_t(second) > 0 && (int16_t(first+second) & (1 << 15)))
			sr |= 0x10;
	//Overflow detection for subtraction
	} else if ((OP == 4) || (OP == 5)) {
		//Tests if positive minus a negative makes a negative number
		if (int16_t(first) > 0 && int16_t(second) < 0 && (int16_t(first-second) & (1 << 15))) {
			sr |= 0x10;
		//Tests if negative minus a positive makes a positive number
		} else if (int16_t(first) < 0 && int16_t(second) > 0 && !(int16_t(first-second) & (1 << 15))) {
			sr |= 0x10;
		}
	}
}
