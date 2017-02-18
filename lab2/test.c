#include "mySimpleComputer.h"

int main(){
	sc_memoryInit(); //инициализируем память
	
	//запишем кое-что в память
	//------------------------------------
	sc_memorySet(9,7);
	sc_memorySet(5,7);
	sc_memorySet(60,7);
	sc_memorySet(95,7);
	//------------------------------------
	
	//получим из памяти что-нибудь
	//------------------------------------
	int m_get1 = sc_memoryGet(5,&m_get1);
	int m_get2 = sc_memoryGet(99,&m_get2);
	printf("m_get1=%d, m_get2=%d\n\n", m_get1, m_get2);
	//------------------------------------
	
	//сохраним память в бинарник и распечатаем память
	//------------------------------------
	sc_memorySave("my_memory.bin");
	my_print();
	//------------------------------------
	
	//загрузим память из бинарника и распечатаем память
	//------------------------------------
	sc_memoryLoad ("my_memory.bin");
	my_print();
	//------------------------------------
	
	//поработаем с регистром флагов
	//------------------------------------
	sc_regInit(); //зануляем все флаги
	printf("reg=%d\n",reg); // вывод регистра
	
	sc_regSet(FLAG_T, 1); //установим флаг T в единицу
//	sc_regSet(FLAG_E, 1);
//	sc_regSet(FLAG_O, 1);
//	sc_regSet(FLAG_P, 1);
//	sc_regSet(FLAG_M, 1);
	printf("reg=%d",reg); // вывод регистра
	
	int flg_T = sc_regGet(FLAG_T, &flg_T); // вернем значение флага T
	int flg_O = sc_regGet(FLAG_O, &flg_O); // вернем значение флага O
	printf("\nflg_T=%d, flg_O=%d\n",flg_T, flg_O); // вывод значения флагов T и O
	//------------------------------------
	
	//кодирование и декодирование команд
	//------------------------------------
	int cmd_encode = sc_commandEncode(0x21, 4, &cmd_encode); // закодируем команду и операнд
	printf("\ncmd_encode=%d\n",cmd_encode); // вывод полученного
	
	int op_decode, cmd_decode;
	sc_commandDecode(cmd_encode, &cmd_decode, &op_decode); // декодируем ранее закодированную команду
	printf("\ncmd_decode=%d, op_decode=%d",cmd_decode, op_decode); // вывод полученного
	//------------------------------------
	
	return 0;	
}
