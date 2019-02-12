#include "../include/memory.h"

namespace emulator
{
	Memory::Memory()
		: MAX_ADDRESS(255), m_Memory(new Byte[MAX_ADDRESS])
	{
	}

	Memory::~Memory() 
	{ 
		if (m_Memory != nullptr) { delete[] m_Memory; m_Memory = nullptr; }
	}

	void Memory::clear()
	{
		for(Byte i = 0; i < MAX_ADDRESS; i++)
			m_Memory[i] = 0;
	}

	Byte& Memory::Read(const Byte& m_Address) { return m_Memory[m_Address]; }

	void Memory::Write(const Byte& m_Address, const Byte& value) { m_Memory[m_Address] = value; }
	
	void Memory::Dump()
	{
		for(Byte i = 0; i < MAX_ADDRESS; i++)
			std::cout << "[ " << (int)i << " ]" << " ===> " << (int)Read(i) << std::endl;
	}	
}