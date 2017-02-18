#ifndef __MYTERM
#define __MYTERM

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

enum colors {
	clr_black,
	clr_red,
	clr_green,
	clr_brown,
	clr_blue,
	clr_magenta,
	clr_cyan,
	clr_light_blue,
	clr_default
};

int mt_clrscr (void);
int mt_gotoXY (int x, int y);
int mt_getscreensize(int *rows, int *cols);
int mt_setbgcolor(enum colors color);


#endif
