os: os.cpp VirtualMachine.o Assembler.o
	g++ -o os os.cpp VirtualMachine.o Assembler.o


VirtualMachine.o: VirtualMachine.h VirtualMachine.cpp
	g++ -c -std=c++11 VirtualMachine.cpp
    
Assembler.o: Assembler.h Assembler.cpp
	g++ -c Assembler.cpp
    
clean:
	rm *.o prog.o
