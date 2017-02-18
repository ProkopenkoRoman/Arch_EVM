#ifndef __MYSIMPLECOMPUTER
#define __MYSIMPLECOMPUTER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define FLAG_P 1
#define FLAG_O 2
#define FLAG_M 3
#define FLAG_T 4
#define FLAG_E 5

#define MEMSIZE 100
#define COMMANDS_COUNT 37 //см. таблицу комманд в pdf-документе

int my_memory[MEMSIZE]; //оперативная память
int reg; //регистр флагов

void my_print(); //печать содержимого оперативной памяти
//////
int sc_memoryInit (); //инициализирует оперативную память Simple Computer, задавая всем ее ячейкам нулевые значения
int sc_memorySet (int address, int value); //задает значение указанной ячейки памяти как value
int sc_memoryGet (int address, int * value); //возвращает значение указанной ячейки памяти в value
int sc_memorySave (char * filename); //сохраняет содержимое памяти в файл в бинарном виде
int sc_memoryLoad (char * filename); //загружает из указанного файла содержимое оперативной памяти
/**********/
int sc_regInit (); //инициализирует регистр флагов нулевым значением
int sc_regSet (int my_reg, int value); //устанавливает значение указанного флага
int sc_regGet (int my_reg, int * value); //возвращает значение указанного флага
int sc_commandEncode (int command, int operand, int * value); //кодирует команду с указанным номером и операндом и помещает результат в value
int sc_commandDecode (int value, int * command, int * operand); //декодирует значение как команду Simple Computer
/////


#endif
