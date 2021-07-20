
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
