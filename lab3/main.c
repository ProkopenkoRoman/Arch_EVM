#include "myTerm.h"

int main(){
	mt_clrscr ();
	
	int r, c;
	mt_gotoXY (10, 10);
	mt_getscreensize(&r, &c);
	//printf("r=%d c=%d", r, c);
	//mt_setbgcolor(enum colors color);

	return 0;	
}
