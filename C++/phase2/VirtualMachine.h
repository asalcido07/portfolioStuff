
// Virtual Machine.h

#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class VirtualMachine 
{
    friend class OS;
    private:
        typedef void (VirtualMachine::*FP)();
        map <int, FP> instructions;
        map <int, int> op_clk_ticks;
        int total_memory_used; //used to keep track of how many spaces in memory are being used total
        static const int REG_FILE_SIZE = 4;
        static const int MEM_SIZE = 256;
        vector <int> r;
        vector <int> mem;
        int pc;
        int ir;
        int sr;
        int sp;
        int base;
        int limit;
        int clk;
        bool flag;
        fstream * input;
        fstream * output;
        
        
    public:                                                 // Took out fetch and execute
        VirtualMachine();
        void run(); //added parameter to keep track of initial time that process was loaded into VM
        void decode();
        void load_i(); // Key values are like previous map
    	void store();
        void add_i();
        void add_c_i();
        void sub_i();
	    void sub_c_i();
	    void and_i();
	    void xor_i();
	    void compl_();
	    void shl();
	    void shla();
	    void shr();
	    void shra();
	    void compr_i();
	    void get_stat();
	    void put_stat();
    	void jump();
	    void jump_l();
        void jump_e();
    	void jump_g();
        void call();
        void return_();
        void read();
        void write();
        void halt();
        void noop();
        void overflow_detect(int, int, int);

    	
};

class format1 {
    public:
        unsigned UNUSED:6;
        unsigned RS:2;
        unsigned I:1;
        unsigned RD:2;
        unsigned OP:5;
};
        
class format2 {
    public:
        unsigned ADDR:8;
        unsigned I:1;
        unsigned RD:2;
        unsigned OP:5;
};
        
        
class format3 {
    public:
        int CONST:8;
        unsigned I:1;
        unsigned RD:2;
    	unsigned OP:5;
};
        
union instruction {
    int i;
    format1 f1;
    format2 f2;
    format3 f3;
};
#endif