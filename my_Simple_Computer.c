#include <stdio.h>
#include <stdlib.h>

#define FLAG_P 00001;
#define FLAG_M 00010;
#define FLAG_O 00100;
#define FLAG_T 01000;
#define FLAG_E 0b10000;

int sc_memoryInit ();
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int * value);
int sc_memorySave (char * filename);
int sc_memoryLoad (char * filename);
int sc_regInit ();
int sc_regSet (int register, int value);
/////
void my_print();

int my_memory [100];
int reg;

int main(){
	sc_memoryInit();
	sc_memorySet(9,6);
	sc_memorySet(5,6);
	sc_memorySet(60,6);
	sc_memorySet(95,6);
	
	sc_memorySave("ololo.bin");
	my_print();
	sc_memoryLoad ("ololo.bin");
	
	
	my_print();
	
	return 0;	
}
///////
void my_print(){
	int i;
	for(i = 0; i < 100; i++){
		printf("%d", my_memory[i]);
		if (i != 0 && i % 10 == 0 )
			printf("\n");
	}
		printf("\n\n\n");
}
/////////
int sc_memoryInit (){
	int i;
	for(i = 0; i < 100; i++)
		my_memory[i] = 0;
return 0;
}

int sc_memorySet (int address, int value){
	if(address < 0 || address >= 100){
		return -1;
	} 
	else 
	my_memory[address] = value;
	return 0;		
}

int sc_memoryGet (int address, int *value){
	if(address < 0 || address >= 100){
		return -1;
	}
	else  *value = my_memory[address];	
	return 0;
}

int sc_memorySave (char *filename){
	FILE *f ;
	f = fopen(filename, "w+b");
	if(f == NULL) {
		return -1;
	}
	int i;
	for(i = 0; i < 100; i++){
		fwrite(&my_memory[i], sizeof(int), 1, f);
	}
	fclose(f); 
	return 0;
}

int sc_memoryLoad (char * filename){
	FILE *f ;
	f = fopen(filename,"rb");
	if(f == NULL) {
		return -1;
	}
	int i;
	for(i = 0; i < 100; i++){
		fread(my_memory, sizeof(my_memory), 1, f);
	}
	fclose(f); 
	return 0;
}
int sc_regInit (){
	reg = 0;
	return 0;
}

int sc_regSet (int register, int value){
	
}
