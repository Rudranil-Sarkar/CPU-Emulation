A simple emulation of a cpu
## Cpu architecture:
- One ProgramCounter
- 2 1byte registers
- one underflow flag
- one overflow flag
- one Signed number flag

## Operations

Operation Code | Description
---------------|--------------------------------------------------------------
LR0 `<value>`  | Directly load the value onto the Register0
LR1 `<value>`  | Directly load the value onto the Register1
LD0 `<addr>`   | Load the value in the given memory address into Register0.
LD1 `<addr>`   | Load the value in the given memory address into Register1.
ADD            | Add both registers and store the result in Register0.
STR `<addr>`   | Store the value in Register0 in the given memory address.
PRT `<addr>`   | Print the value in the given memory address.
JMP `<addr>`   | Jump to the given memory address.
JPQ `<addr>`   | Jump to the given memory address if both Registers are equal.
CL0            | Set the Register0 to zero.
CL1            | Set the Register1 to zero.
CP0            | Copy the value in Register0 into Register1.
CP1            | Copy the value in Register1 into Register0.
BEL            | Make the computer "beep".
HAL            | Stop execution


## Running a program
Navigate to the src dir then
~~~
g++ --std=c++11 cpu.cpp memory.cpp CodeParser.cpp Application.cpp
./`name of the binary` `<path_to_program>`
