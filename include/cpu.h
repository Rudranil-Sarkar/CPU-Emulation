#pragma once
#include "./opcode.h"
#include "./memory.h"

namespace emulator
{
	class CPU
	{
		public:
			const Byte OP_ADD;
			const Byte FIRST_ADD;
			const Byte JUMP_ADD;
			const Byte MAX_ADDRESS;

		private:
			Memory * p_Memory;
			
			Byte ProgramCounter;		 // The Program Counter for pointing to the next operation
			Byte Reg0; 					// The first registor
			Byte Reg1; 				  // The second registor

			bool Signed;
			bool Overflow;
			bool Underflow;
			bool HaltState;

		public:
			/* The cpu constructor gonna take a memory object
			   This way the we can use multiple cpus in a same program */
			CPU(Memory * mem);
			~CPU();

			void Run();
			void Reset();

		private:
			Byte fetch();
			void decode(const Byte& operation);

			/* These are the OPcode function */

			void halt();
			void lodr0(); // These load gonna directly
			void lodr1(); // load a value onto the registors

			void load0(); // These load gonna load a value
			void load1(); // from a given memory address to the registor
			
			void add();
			void store();
			void print();
			void jump();
			void jumpeq();
			void clear0();
			void clear1();
			void copy0();
			void copy1();
			void beep();
		
	};
}