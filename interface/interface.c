#include "interface.h" 

void print_frames(){	
	//memory
	bc_box(1, 1, 62, 12);
	mt_gotoXY(27, 1);
	write(1, " Memory ", 9);
	//small ramka
	bc_box(64, 1, 85, 3);
	mt_gotoXY(68, 1);
	write(1, " accumulator ", 13);
	
	bc_box(64, 4, 85, 6);
	mt_gotoXY(65, 4);
	write(1, " InstructionCounter ", 20);
	
	bc_box(64, 7, 85, 9);
	mt_gotoXY(69, 7);
	write(1, " Operation ", 11);
	
	bc_box(64, 10, 85, 12);
	mt_gotoXY(71, 10);
	write(1, " Flags ", 7);
	
	//
	bc_box(1, 13, 47, 22);
	bc_box(48, 13, 85, 22);
	mt_gotoXY(49,13);
	write(1, " Keys: ", 7);
	
	mt_gotoXY(1,23);
}

void printMemory(){
	int i, y = 2, x = 2;
	char buf[6];
    char *memElem = "+%.4X";
	
	for(i = 0; i < MEMSIZE; i++){
		if (i != 0 && i % 10 == 0){
			x += 6;
			y = 2;
		}
		mt_gotoXY(x,y);
		if (sprintf(buf, memElem, my_memory[i]) > 0) {
			if (write(1, buf, strlen(buf)) == -1)
				exit(1);
		}
		y++;		
	}
	mt_gotoXY(1,23);
}

void printFlags(){
	
	mt_gotoXY(70,11);
	
	write(1,"P O M T E", 9);

}
