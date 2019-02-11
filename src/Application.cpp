#include <iostream>
#include "../include/emulator.h"

int main(int argc, char* argv[])
{
	std::cout << ":: Initializing memory\n";
	emulator::Memory* memory = new emulator::Memory();

	std::cout << ":: Initializing CPU\n";
	emulator::CPU* cpu = new emulator::CPU(memory);

	if(argc >= 2)
		emulator::CodeParser code(memory, cpu -> FIRST_ADD, argv[1]);

	std::cout << ":: The cpu is Running\n";

	//memory -> Dump();

	cpu->Run();

	std::cout << ":: The Computer Shutting down\n";
	delete memory;
	delete cpu;

	return 0;
}