#include "../include/CodeParser.h"

namespace emulator {

	CodeParser::CodeParser(Memory * mem, Byte offset, const char* filepath)
		: m_Offset(offset), m_Counter(0), m_Mem(mem)
	{
		std::ifstream file;
		std::string line;

		file.open(filepath, std::ifstream::in);

		if(file.is_open())
		{
			while(getline(file, line))
				parse(line);
		}
	}

	void CodeParser::parse(std::string line)
	{
		std::string op;
		std::string addr;

		if(line.length() < 4)
		{
			load(std::stoi(line.substr(0, line.find(';'))));
			return;
		}

		op = line.substr(0, 3);
		addr = line.substr(4, line.find(';'));

		if(op == "HAL") { load(HALT); }
		else if (op == "LR0") { load(LOADR0); load(std::stoi(addr)); }
		else if (op == "LR1") { load(LOADR1); load(std::stoi(addr)); }
		else if (op == "LD0") { load(LOAD0); load(std::stoi(addr)); }
		else if (op == "LD1") { load(LOAD1); load(std::stoi(addr)); }
		else if (op == "ADD") { load(ADD); }
		else if (op == "STR") { load(STORE); load(std::stoi(addr)); }
		else if (op == "PRT") { load(PRINT); load(std::stoi(addr)); }
		else if (op == "JMP") { load(JUMP); load(std::stoi(addr)); }
		else if (op == "JEQ") { load(JUMPEQ); load(std::stoi(addr)); }
		else if (op == "CL0") { load(CLEAR0); }
		else if (op == "CL1") { load(CLEAR1); }
		else if (op == "CP0") { load(COPY0); }
		else if (op == "CP1") { load(COPY1); }
		else if (op == "BEL") { load(BEEP); }
		else { std::cout << ":: Invalid code quiting" << std::endl; exit(3); }
	}

	void CodeParser::load(Byte b)
	{
		m_Mem -> Write(m_Offset + m_Counter, b);
		m_Counter++;
	}
}