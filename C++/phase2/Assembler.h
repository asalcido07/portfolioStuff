
// Assembler.h

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Assembler {
    private:
        map<string, int> instruct;
        int opcode, rd, rs, address, format, constant;
        union last_8_bits {
            int negative;
            unsigned int positive:8;
        } sample;
    
    public:
        Assembler();
        void read_file(fstream &, fstream &);
        void check_instructions();
        void write_object_code(fstream &, int i);
};
#endif