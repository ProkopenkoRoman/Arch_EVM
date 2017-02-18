#include "myTerm.h"

int mt_clrscr (){
	write(0, "\E[H\E[2J", 8);
	return 0;
}

int mt_gotoXY(int x, int y)
{
	int rows, cols;
	mt_getscreensize(&rows, &cols);
	if ((y < rows) && (x < cols) && (x >= 0) && (y >= 0)) {
		//printf("\E[%d;%dH", y, x);
		write(0, "\E[%d;%dH", 9);
		return 0;
	}
	else
		return -1;
}

int mt_getscreensize(int *rows, int *cols)
{
	struct winsize w;

	if (!ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)) {
		*rows = w.ws_row;
		*cols = w.ws_col;
		return 0;
	}
	else
		return -1;
}
/*
int mt_setbgcolor(enum colors color)
{
	switch (color) {
		case clr_black:
			printf("\E[40m");
			break;
		case clr_red:
			printf("\E[41m");
			break;
		case clr_green:
			printf("\E[42m");
			break;
		case clr_brown:
			printf("\E[43m");
			break;
		case clr_blue:
			printf("\E[44m");
			break;
		case clr_magenta:
			printf("\E[45m");
			break;
		case clr_cyan:
			printf("\E[46m");
			break;
		case clr_light_blue:
			printf("\E[47m");
			break;
		case clr_default:
			printf("\E[49m");
			break;
		default:
			return -1;
	}
	return 0;
}*/
