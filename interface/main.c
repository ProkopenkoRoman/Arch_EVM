#include "interface.h" 
int main(){

	sc_memoryInit();
	sc_memorySet(0, 5);
	sc_memorySet(1, 8);
	sc_memorySet(2, 15);
	sc_memorySet(2, 9999);
	
	print_frames();
	printFlags();
	printMemory();
	
	return 0; 
}
