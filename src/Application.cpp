#include <iostream>
#include "../include/emulator.h"

int main(int argc, char* argv[])
{
	std::cout << ":: Initializing memory" << std::endl;
	emulator::Memory* memory = new emulator::Memory();
	
	std::cout << ":: Clearing the memory" << std::endl;
	memory->clear();

	std::cout << ":: Initializing CPU" << std::endl;
	emulator::CPU* cpu = new emulator::CPU(memory);

	if (argc >= 2)
	{
		emulator::CodeParser code(memory, cpu->FIRST_ADD);
		code.loadFile(argv[1]);
	}	
		

	std::cout << ":: The cpu is Running" << std::endl;

	//memory -> Dump();

	cpu->Run();

	std::cout << ":: The Computer Shutting down" << std::endl;
	delete cpu;
	delete memory;

	std::cin.get();

	return 0;
}