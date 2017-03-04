#ifndef __MYTERM
#define __MYTERM

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

enum colors{
	black,
	red,
	green,
	yellow,
	blue,
	pink,
	white,
	standart
};

int mt_clrscr ();
int mt_gotoXY(int x, int y);
int mt_getscreensize (int *rows, int *cols);
int mt_setfgcolor (enum colors color);
int mt_setbgcolor (enum colors color);


#endif
