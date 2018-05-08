OS: os.o VirtualMachine.o Assembler.o main.cpp
	g++ -o OS os.o VirtualMachine.o Assembler.o main.cpp

os.o: os.h os.cpp
	g++ -c os.cpp

VirtualMachine.o: VirtualMachine.h VirtualMachine.cpp
	g++ -c -std=c++11 VirtualMachine.cpp
    
Assembler.o: Assembler.h Assembler.cpp
	g++ -c Assembler.cpp
    
clean:
	rm *.o prog.o
