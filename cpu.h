#define r8 unsigned char
#define r16 unsigned short

#define d8 unsigned char
#define d16 unsigned short

typedef unsigned char OPCODE;
d8 MEMORY[65536];

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
    r8 FLAG_REGISTER; //Z: [7], N:[6], H:[5], C:[4]


    void (*execute)(struct CPU *self, OPCODE instruction);
    void (*dump_registers)(struct CPU *self);

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
    
    printf("PC: %x\n", cpu->PC);
    printf("SP: %x\n", cpu->SP);
    printf("Flag Reg: %x\n",cpu->FLAG_REGISTER);
}