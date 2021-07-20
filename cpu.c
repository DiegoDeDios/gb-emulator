#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "opcodes.h"

/*Author: Diego de Dios

References:
    https://meganesulli.com/generate-gb-opcodes/
    http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf
*/


void execute(CPU* cpu, OPCODE instruction){
    return;
}

void reset_cpu(CPU* cpu){
    cpu->AF = 0x0; 
    cpu->BC = 0x0; 
    cpu->DE = 0x0; 
    cpu->HL = 0x0; 
    cpu->SP = 0xFFFE;
    cpu->PC = 0x0;
    cpu->FLAG_REGISTER = 0x0;
}

int main(int argc, char **argv){

    CPU *cpu = (CPU*)malloc(sizeof(CPU));
    cpu->execute = &execute;
    cpu->dump_registers = &dump_registers;

    reset_cpu(cpu);

    cpu->dump_registers(cpu);

    NOP(cpu);
    LD_BC_16(cpu,0xfffe);

    cpu->dump_registers(cpu);

    LD_BC_A(cpu);
    INC_B(cpu);

    cpu->dump_registers(cpu);


    return 0;
}