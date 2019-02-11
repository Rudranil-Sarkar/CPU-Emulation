#pragma once
#include <iostream>

namespace emulator 
{
	typedef unsigned char Byte;

	class Memory
	{
		private:
			Byte * m_Memory; // The actual memory buffer

		public:
			const Byte MAX_ADDRESS;

		public:
			Memory();
			~Memory();

			/* To clear the memory */
			void clear();

			/* To read a byte from the memory */
			Byte& Read(const Byte& m_Address);

			/* To write a value to memory */
			void Write(const Byte& m_Address,const Byte& value);

			/* TO Dump the Memory */
			void Dump();
	};
}