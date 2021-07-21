
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
