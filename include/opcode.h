#pragma once
namespace emulator {

	enum OPCODE
	{
		HALT,   //0
		LOADR0, //1
		LOADR1, //2
		LOAD0,  //3
		LOAD1, // 4
		ADD,   //5
		STORE,  //6
		PRINT,  //7
		JUMP,	//8
		JUMPEQ,	//9
		CLEAR0,	//10
		CLEAR1,	//11
		COPY0,	//12
		COPY1,	//13
		BEEP	//14
	};

};