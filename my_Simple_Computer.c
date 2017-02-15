#include <stdio.h>
#include <stdlib.h>

//восьмеричное представление
#define FLAG_P 01;
#define FLAG_M 02;
#define FLAG_O 04;
#define FLAG_T 010;
#define FLAG_E 020;

int sc_memoryInit (); //инициализирует оперативную память Simple Computer, задавая всем ее ячейкам нулевые значения
int sc_memorySet (int address, int value); //задает значение указанной ячейки памяти как value
int sc_memoryGet (int address, int * value); //возвращает значение указанной ячейки памяти в value
int sc_memorySave (char * filename); //сохраняет содержимое памяти в файл в бинарном виде
int sc_memoryLoad (char * filename); //загружает из указанного файла содержимое оперативной памяти
int sc_regInit (); //инициализирует регистр флагов нулевым значением
int sc_regSet (int my_reg, int value); //устанавливает значение указанного флага
int sc_regGet (int my_reg, int * value); //возвращает значение указанного флага
int sc_commandEncode (int command, int operand, int * value); //кодирует команду с указанным номером и операндом и помещает результат в value
int sc_commandDecode (int value, int * command, int * operand); //декодирует значение как команду Simple Computer
/////
void my_print(); //печать содержимого оперативной памяти

int my_memory [100]; //оперативная память
int reg; //регистр флагов

int main(){
	sc_memoryInit();
	
	sc_memorySet(9,7);
	sc_memorySet(5,7);
	sc_memorySet(60,7);
	sc_memorySet(95,7);
	
	sc_memorySave("my_memory.bin");
	my_print();
	
	sc_memoryLoad ("my_memory.bin");
	my_print();
	
	return 0;	
}
///////
void my_print(){
	int i;
	for(i = 0; i < 100; i++){
		if (i != 0 && i % 10 == 0)
			printf("\n");
		printf("%d", my_memory[i]);
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
	if(address < 0 || address >= 100)
		return -1;
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
	if(f == NULL)
		return -1;
	int i;
	for(i = 0; i < 100; i++)
		fwrite(&my_memory[i], sizeof(int), 1, f);
	fclose(f); 
	return 0;
}

int sc_memoryLoad (char * filename){
	FILE *f ;
	f = fopen(filename,"rb");
	if(f == NULL)
		return -1;
	int i;
	for(i = 0; i < 100; i++)
		fread(my_memory, sizeof(my_memory), 1, f);
	fclose(f); 
	return 0;
}

int sc_regInit (){
	reg = 0;
	return 0;
}

int sc_regSet (int my_reg, int value){
//	if (my_reg != FLAG_P || my_reg != FLAG_M || my_reg != FLAG_O || my_reg != FLAG_T || my_reg != FLAG_E) //проверка на некорректный флаг
//		return -1;
	if (value != 0 || value != 1) //некорректное значение
		return -1;
	
	if (value = 1)
		reg = reg | (1 << (my_reg - 1)); //установить значение флага в единицу
	else reg = reg & (~(1 << (my_reg - 1))); //установить значение флага в ноль
	//reg - переменная хранящая флаги; my_reg - номер разряда(по порядку)
	return 0;
}

int sc_regGet (int my_reg, int * value){
	//	if (my_reg != FLAG_P || my_reg != FLAG_M || my_reg != FLAG_O || my_reg != FLAG_T || my_reg != FLAG_E) //проверка на некорректный флаг
	//		return -1;
	else  *value = (reg >> (my_reg - 1)) & 0x1;	//получаем значение определенного флага
	//reg - переменная хранящая флаги; my_reg - номер разряда(по порядку)
	return 0;
}

int sc_commandEncode (int command, int operand, int * value){
	/////
}

int sc_commandDecode (int value, int * command, int * operand){
	/////
}
