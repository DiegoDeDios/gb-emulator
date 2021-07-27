
//0x0
void NOP(CPU* cpu){
    printf("NOP\n");
}

//0x1
void LD_BC_16(CPU* cpu, d16 data){
    cpu->BC = data;
}

//0x2
void LD_BC_A(CPU* cpu){
    MEMORY[cpu->BC] = cpu->A;
}

//0x3
void INC_BC(CPU* cpu){
    cpu->BC++;
}

//0x4
void INC_B(CPU* cpu){
    //Check for H first
    if(((cpu->B & 0xf) + 1) & 0x10){ //If the lower nibble of reg overflows
        cpu->FLAG_REGISTER |= (0x1 << 5); //Set H flag to 1
    }
    cpu->B++;
    if (cpu->B == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); //Set Z flag to 1
    }
    cpu->FLAG_REGISTER &= 0xbf; // 0xbf->0b10111111 turning bit 6 (N flag) off 
}

//0x5
void DEC_B(CPU* cpu){
    //Check for H first
    if(((cpu->B & 0xf) + 1) & 0x10){ 
        cpu->FLAG_REGISTER |= (0x1 << 5); 
    }
    cpu->B--;
    if (cpu->B == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); 
    }
    cpu->FLAG_REGISTER |= (0x1 << 6);//Now turning on

}

//0x6
void LD_B_8(CPU* cpu, d8 data){
    cpu->B = data;
}


//0x7 pending...

//0x8
void LD_A16_SP(CPU* cpu, d16 address){
    MEMORY[address] = cpu->SP & 0xff;
    MEMORY[address + 1] = (cpu->SP >> 8);
}

//0x9
void ADD_HL_BC(CPU* cpu){
    if(((cpu->L & 0xf) + 1) & 0x10){ //If the lower nibble of reg overflows
        cpu->FLAG_REGISTER |= (0x1 << 5); //Set H flag to 1
    }
    if(((cpu->HL & 0xffff) + 1) & 0x10000){
        cpu->FLAG_REGISTER |= (0x1 << 4); //Set C flag to 1
    }
    cpu->HL+=cpu->BC;

    cpu->FLAG_REGISTER &= 0xbf; // 0xbf->0b10111111 turning bit 6 (N flag) off 
}

//0xA
void LD_A_BC(CPU* cpu){
    cpu->A = MEMORY[cpu->BC];
}

//0xB
void DEC_BC(CPU* cpu){
    cpu->BC--;
}

//0xC
void INC_C(CPU* cpu){
    if(((cpu->C & 0xf) + 1) & 0x10){ //If the lower nibble of reg overflows
        cpu->FLAG_REGISTER |= (0x1 << 5); //Set H flag to 1
    }
    cpu->C++;
    if (cpu->C == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); //Set Z flag to 1
    }
    cpu->FLAG_REGISTER &= 0xbf; // 0xbf->0b10111111 turning bit 6 (N flag) off 
}

//0xD
void DEC_C(CPU* cpu){
    //Check for H first
    if(((cpu->C & 0xf) + 1) & 0x10){ 
        cpu->FLAG_REGISTER |= (0x1 << 5); 
    }
    cpu->C--;
    if (cpu->C == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); 
    }
    cpu->FLAG_REGISTER |= (0x1 << 6);//Now turning on

}

//0xE
void LD_C_8(CPU* cpu, d8 data){
    cpu->C = data;
}

//0xF 
//Pending....

//0x10
void STOP(CPU* cpu){
    //Pending... need to implement interrupts and CLK signals
}


//0x11
void LD_DE_16(CPU* cpu, d16 data){
    cpu->DE = data;
}

//0x12
void LD_DE_A(CPU* cpu){
    MEMORY[cpu->DE] = cpu->A;
}

//0x13
void INC_DE(CPU* cpu){
    cpu->DE++;
}

//0x14
void INC_D(CPU* cpu){
    if(((cpu->D & 0xf) + 1) & 0x10){ //If the lower nibble of reg overflows
        cpu->FLAG_REGISTER |= (0x1 << 5); //Set H flag to 1
    }
    cpu->D++;
    if (cpu->D == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); //Set Z flag to 1
    }
    cpu->FLAG_REGISTER &= 0xbf; // 0xbf->0b10111111 turning bit 6 (N flag) off 
}

//0x15
void DEC_D(CPU* cpu){
    //Check for H first
    if(((cpu->D & 0xf) + 1) & 0x10){ 
        cpu->FLAG_REGISTER |= (0x1 << 5); 
    }
    cpu->D--;
    if (cpu->D == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); 
    }
    cpu->FLAG_REGISTER |= (0x1 << 6);//Now turning on
}

//0x16
void LD_D_8(CPU* cpu, d8 data){
    cpu->D = data;
}

//0x17 Pending... another rotation

//0x18
void JR(CPU* cpu, d8 steps){
    cpu->PC+=steps;
    //TODO:Do we have to store the previous PC into the sp?
}

//0x19
void ADD_HL_DE(CPU* cpu){
    if(((cpu->L & 0xf) + 1) & 0x10){ //If the lower nibble of reg overflows
        cpu->FLAG_REGISTER |= (0x1 << 5); //Set H flag to 1
    }
    if(((cpu->HL & 0xffff) + 1) & 0x10000){
        cpu->FLAG_REGISTER |= (0x1 << 4); //Set C flag to 1
    }
    cpu->HL+=cpu->DE;

    cpu->FLAG_REGISTER &= 0xbf; // 0xbf->0b10111111 turning bit 6 (N flag) off 
}

//0x1A
void LD_A_DE(CPU* cpu){
    cpu->A = MEMORY[cpu->DE];
}

//0x1B
void DEC_DE(CPU* cpu){
    cpu->DE--;
}

//0x1C
void INC_E(CPU* cpu){
    if(((cpu->E & 0xf) + 1) & 0x10){ //If the lower nibble of reg overflows
        cpu->FLAG_REGISTER |= (0x1 << 5); //Set H flag to 1
    }
    cpu->E++;
    if (cpu->E == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); //Set Z flag to 1
    }
    cpu->FLAG_REGISTER &= 0xbf; // 0xbf->0b10111111 turning bit 6 (N flag) off 
}

//0x1D
void DEC_E(CPU* cpu){
    if(((cpu->E & 0xf) + 1) & 0x10){ 
        cpu->FLAG_REGISTER |= (0x1 << 5); 
    }
    cpu->E--;
    if (cpu->E == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); 
    }
    cpu->FLAG_REGISTER |= (0x1 << 6);//Now turning on
}

//0x1E
void LD_E_8(CPU* cpu, d8 data){
    cpu->E = data;
}

//0x1F pending....

//0x20

void JR_NZ_8(CPU* cpu, d8 steps){
    if (cpu->FLAG_REGISTER >> 7){
        cpu->PC++;
    }
    else{
        cpu->PC+=steps;
    }
}

//0x21
void LD_HL_16(CPU* cpu, d16 data){
    cpu->HL = data;
}

//0x22
void LD_HLP_A(CPU* cpu){
    MEMORY[cpu->HL++]=cpu->A;
}

//0x23
void INC_HL(CPU* cpu){
    cpu->HL++;
}

//0x24
void INC_H(CPU* cpu){
    if(((cpu->H & 0xf) + 1) & 0x10){ //If the lower nibble of reg overflows
        cpu->FLAG_REGISTER |= (0x1 << 5); //Set H flag to 1
    }
    cpu->H++;
    if (cpu->H == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); //Set Z flag to 1
    }
    cpu->FLAG_REGISTER &= 0xbf; // 0xbf->0b10111111 turning bit 6 (N flag) off 
}

//0x25
void DEC_H(CPU* cpu){
    //Check for H first
    if(((cpu->D & 0xf) + 1) & 0x10){ 
        cpu->FLAG_REGISTER |= (0x1 << 5); 
    }
    cpu->D--;
    if (cpu->D == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); 
    }
    cpu->FLAG_REGISTER |= (0x1 << 6);//Now turning on

}

//0x26
void LD_H_8(CPU* cpu, d8 data){
    cpu->H = data;
}

//0x27 Pending... BCD

//0x28

void JR_Z_8(CPU* cpu, d8 steps){
    if (cpu->FLAG_REGISTER >> 7){
        cpu->PC+=steps;
    }
    else{
        cpu->PC++;
    }
}

//0x29
void ADD_HL_HL(CPU* cpu){
    if(((cpu->L & 0xf) + 1) & 0x10){ //If the lower nibble of reg overflows
        cpu->FLAG_REGISTER |= (0x1 << 5); //Set H flag to 1
    }
    if(((cpu->HL & 0xffff) + 1) & 0x10000){
        cpu->FLAG_REGISTER |= (0x1 << 4); //Set C flag to 1
    }
    cpu->HL+=cpu->HL;

    cpu->FLAG_REGISTER &= 0xbf; // 0xbf->0b10111111 turning bit 6 (N flag) off 
}

//0x2A
void LD_A_HLP(CPU* cpu){
    cpu->A = MEMORY[cpu->HL++];
}

//0x2B
void DEC_HL(CPU* cpu){
    cpu->HL--;
}

//0x2C
void INC_L(CPU* cpu){
    if(((cpu->L & 0xf) + 1) & 0x10){ //If the lower nibble of reg overflows
        cpu->FLAG_REGISTER |= (0x1 << 5); //Set H flag to 1
    }
    cpu->L++;
    if (cpu->L == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); //Set Z flag to 1
    }
    cpu->FLAG_REGISTER &= 0xbf; // 0xbf->0b10111111 turning bit 6 (N flag) off 
}

//0x2D
void DEC_L(CPU* cpu){
    if(((cpu->L & 0xf) + 1) & 0x10){ 
        cpu->FLAG_REGISTER |= (0x1 << 5); 
    }
    cpu->L--;
    if (cpu->L == 0){
        cpu->FLAG_REGISTER |= (0x1 << 7); 
    }
    cpu->FLAG_REGISTER |= (0x1 << 6);//Now turning on
}

//0x2E
void LD_L_8(CPU* cpu, d8 data){
    cpu->L = data;
}

//0x2F
void CPL(CPU* cpu){
    cpu->A = ~(cpu->A); //Taking 1's compliment of A
}