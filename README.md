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
LD0 `<addr>`   | Load the value in the given memory address into Register 0.
LD1 `<addr>`   | Load the value in the given memory address into Register 1.
ADD            | Add both registers and store the result in Register 0.
STR `<addr>`   | Store the value in register 0 in the given memory address.
PRT `<addr>`   | Print the value in the given memory address.
JMP `<addr>`   | Jump to the given memory address.
JPQ `<addr>`   | Jump to the given memory address if both Registers are equal.
CL0            | Set the Register 0 to zero.
CL1            | Set the Register 1 to zero.
CP0            | Copy the value in Register 0 into Register 1.
CP1            | Copy the value in Register 1 into Register 0.
BEP            | Make the computer "beep".
HAL            | Stop execution


## Running a program
first compile then
~~~
./`name of the binary` `<path_to_program>`
