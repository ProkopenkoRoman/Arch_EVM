#include "myTerm.h"

int main(){
	mt_clrscr (); //î÷èñòêà ýêðàíà
	getchar();
	
	int r=0, c=0;
	mt_gotoXY (10, 10); //ïåðåâîä óêàçàòåëÿ â ïîçèöèþ 10,10
	getchar();

	mt_getscreensize(&r, &c); //ïîëó÷åíèå ðàçìåðà òåðìèíàëà
	printf("rows=%d, cols=%d\n", r, c);
	getchar();
	
	mt_setbgcolor(black); //óñòàíîâèì öâåò ôîíà íà áåëûé
	mt_setfgcolor(red); //óñòàíîâèì öâåò ñèìâîëîâ íà æåëòûé
	printf("IV-521, Prokopenko RP\n");
	getchar();
	
	mt_setbgcolor(white); //óñòàíîâèì öâåò ôîíà íà áåëûé
	mt_setfgcolor(black); //óñòàíîâèì öâåò ñèìâîëîâ íà æåëòûé
	return 0;	
}

