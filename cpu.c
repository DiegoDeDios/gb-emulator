#include <stdio.h>
#include <stdlib.h>

#define r8 unsigned char
#define r16 unsigned short

typedef struct CPU{
    union{
        struct{
            r8 F;
            r8 A;
        };
        r16 AF;
    };
    union{
        struct{
            r8 C;
            r8 B;
        };
        r16 BC;
    };
    union{
        struct{
            r8 E;
            r8 D;
        };
        r16 DE;
    };
    union{
        struct{
            r8 L;
            r8 H;
        };
        r16 HL;
    };
    r16 SP;
    r16 PC;
    r8 FLAG_REGISTER;

}CPU;

void dump_registers(CPU* cpu){
    printf("--------8-bit Registers-----------\n");
    printf("A: %x\n",cpu->A);
    printf("B: %x\n",cpu->B);
    printf("C: %x\n",cpu->C);
    printf("D: %x\n",cpu->D);
    printf("E: %x\n",cpu->E);
    printf("F: %x\n",cpu->F);
    printf("H: %x\n",cpu->H);
    printf("L: %x\n",cpu->L);

    printf("--------16-bit Registers-----------\n"); 
    printf("AF: %x\n",cpu->AF);
    printf("BC: %x\n",cpu->BC);
    printf("CE: %x\n",cpu->DE);
    printf("HL: %x\n",cpu->HL);
}

int main(int argc, char **argv){

    CPU *cpu = (CPU*)malloc(sizeof(CPU));

    cpu->AF = 0xdead; //A = de F = ad
    cpu->BC = 0xcafe; // B = ca; C = fe;
    cpu->DE = 0xbeef; // D = be; E = ef;
    cpu->HL = 0xbadd; // H = 0xba; L = dd;

    dump_registers(cpu);

    cpu->A = 0xff;
    cpu->L = 0xff;

    dump_registers(cpu);
    return 0;
}