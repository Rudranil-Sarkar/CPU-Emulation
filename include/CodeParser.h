/* This class is for only to load a Program from a text file onto the main memory of the
	system */
#pragma once
#include <fstream>
#include <string>
#include "./opcode.h"
#include "./memory.h"

namespace emulator {
	
	class CodeParser
	{
		private:
			Byte m_Offset;
			Byte m_Counter;
			Memory* m_Mem;

		public:
			CodeParser(Memory * mem, Byte offset);
			void loadFile(const char * filepath);
		
		private:
			void parse(std::string& line);
			void load(Byte b);
	};
}