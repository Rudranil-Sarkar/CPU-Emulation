#include "../include/cpu.h"

namespace emulator
{
	CPU::CPU(Memory * mem)
		: OP_ADD(0), FIRST_ADD(2), JUMP_ADD(1), MAX_ADDRESS(253),
		  p_Memory(mem), ProgramCounter(FIRST_ADD), Reg0(0), Reg1(0), Signed(false),
		  Overflow(false), Underflow(false), HaltState(false)
		  { }

	CPU::~CPU()
	{
		p_Memory = nullptr;
	}

	void CPU::Run()
	{
		/* While the haltRegistor is not triggered the cpu runs in a loop */
		while(!HaltState)
		{
			/* Fetch the instruction and Store it in the operation Memory block */
			p_Memory -> Write(OP_ADD, fetch());

			/* Decode The instruction */
			decode(p_Memory -> Read(OP_ADD));
		}		
	}

	void CPU::Reset()
	{
		ProgramCounter = FIRST_ADD;
		Reg0 = 0;
		Reg1 = 0;
		Signed = false;
		Overflow = false;
		Underflow = false;
		HaltState = false;
	}

	Byte CPU::fetch()
	{
		Byte B = 0;
		B = p_Memory -> Read(ProgramCounter);
		ProgramCounter++;
		return B;
	}

	void CPU::decode(const Byte& operation)
	{
		switch(operation)
		{
			case HALT:
				halt();
				break;

			case LOADR0:
				lodr0();
				break;

			case LOADR1:
				lodr1();
				break;

			case LOAD0:
				load0();
				break;

			case LOAD1:
				load1();
				break;

			case ADD:
				add();
				break;

			case STORE:
				store();
				break;

			case PRINT:
				print();
				break;

			case JUMP:
				jump();
				break;

			case JUMPEQ:
				jumpeq();
				break;

			case CLEAR0:
				clear0();
				break;

			case CLEAR1:
				clear1();
				break;

			case COPY0:
				copy0();
				break;

			case COPY1:
				copy1();
				break;

			case BEEP:
				beep();
				break;
		}
	}

	void CPU::halt() { HaltState = true; }

	void CPU::lodr0()
	{
		Reg0 = p_Memory -> Read(ProgramCounter); 

		if((char) Reg0 < 0)
			Signed = true;
		else
			Signed = false;

		ProgramCounter++;
	}
	void CPU::lodr1()
	{
		Reg1 = p_Memory -> Read(ProgramCounter);
		
		if((char)Reg1 < 0)
			Signed = true;
		else
			Signed = false;

		ProgramCounter++;
	}

	void CPU::load0()
	{
		Reg0 = p_Memory -> Read(ProgramCounter);
		ProgramCounter++;

		Reg0 = p_Memory -> Read(Reg0);

			if((char) Reg0 < 0)
				Signed = true;
			else
				Signed = false;
	}
	void CPU::load1()
	{
		Reg1 = p_Memory -> Read(ProgramCounter);
		ProgramCounter++;

		Reg1 = p_Memory -> Read(Reg1);

		if((char) Reg1 < 0)
			Signed = true;
		else
			Signed = false;
	}

	void CPU::add()
	{
		Reg0 = Reg0 + Reg1;
		
		if((char) Reg0 < 0)
			Signed = true;
		else
			Signed = false;
	}

	void CPU::store()
	{
		Reg1 = fetch();

		if((char)Reg0 < 0)
			Signed = true;
		else
			Signed = false;
		
		p_Memory -> Write(Reg1, Reg0);
	}

	void CPU::print()
	{
		Reg1 = p_Memory -> Read(ProgramCounter);
		Reg0 = p_Memory -> Read(Reg1);

		if(!Signed)
			std::cout << "------> " << (int)Reg0 << std::endl;
		else
			std::cout << "------> " << (int)(char)Reg0 << std::endl;

		ProgramCounter++;
 	}

 	void CPU::jump()
 	{
 		p_Memory -> Write(JUMP_ADD, p_Memory -> Read(ProgramCounter));

 		ProgramCounter = JUMP_ADD;
 	}

 	void CPU::jumpeq()
 	{
 		if(Reg0 == Reg1)
 			jump();
 		
 		else
 			ProgramCounter++;
 	}

 	void CPU::clear0() { Reg0 = 0; }
 	void CPU::clear1() { Reg1 = 0; }

 	void CPU::copy0() { Reg1 = Reg0; }
 	void CPU::copy1() { Reg0 = Reg1; }

 	void CPU::beep() { std::cout << (char) 7; }

	
}