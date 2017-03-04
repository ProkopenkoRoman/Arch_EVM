#include "myTerm.h"

int mt_clrscr (){
	write(1, "\E[H\E[2J", 8);
	return 0;
}

int mt_gotoXY(int x, int y){
    char buf[15];
    char *gotoxy = "\E[%d;%dH";

    if (sprintf(buf, gotoxy, y, x) > 0) {
	if (write(1, buf, strlen(buf)) == -1)
	    return -1;
    }
    return 0;
}

int mt_getscreensize (int *rows, int *cols){
    struct winsize size;
    
    if (!ioctl(1, TIOCGWINSZ, &size) < 0)
    {
		
		perror("ioctl");
		return -1;
	}

    *rows = size.ws_row;
    *cols = size.ws_col ;
    
    return 0;
}

int mt_setfgcolor (enum colors color){
    char *color_text[] = {"\E[30m", "\E[31m", "\E[32m", "\E[33m", "\E[34m",  "\E[35m", "\E[37m", "\E[39m"};
    
    switch(color) {
	case black:
	    write(1, color_text[0], strlen(color_text[0]));
	    break;
	case red:
	    write(1, color_text[1], strlen(color_text[1]));
	    break;
	case green:
	    write(1, color_text[2], strlen(color_text[2]));
	    break;
	case yellow:
	    write(1, color_text[3], strlen(color_text[3]));
	    break;
	case blue:
	    write(1, color_text[4], strlen(color_text[4]));
	    break;
	case pink:
	    write(1, color_text[5], strlen(color_text[5]));       
	    break;
	case white:
	    write(1, color_text[6], strlen(color_text[6]));       
	    break;
	case standart:
	    write(1, color_text[7], strlen(color_text[7]));       
	    break;
	default:
	    printf("Color not found\n");
	    break;
    }
}

int mt_setbgcolor (enum colors color){
    char *color_fons[] = {"\E[40m", "\E[41m", "\E[42m", "\E[43m", "\E[44m",  "\E[45m", "\E[47m", "\E[49m"};
    
    switch(color) {
	case black:
	    write(1, color_fons[0], strlen(color_fons[0]));
	    break;
	case red:
	    write(1, color_fons[1], strlen(color_fons[1]));
	    break;
	case green:
	    write(1, color_fons[2], strlen(color_fons[2]));
	    break;
	case yellow:
	    write(1, color_fons[3], strlen(color_fons[3]));
	    break;
	case blue:
	    write(1, color_fons[4], strlen(color_fons[4]));
	    break;
	case pink:
	    write(1, color_fons[5], strlen(color_fons[5]));       
	    break;
	case white:
	    write(1, color_fons[6], strlen(color_fons[6]));       
	    break;
	case standart:
	    write(1, color_fons[7], strlen(color_fons[7]));       
	    break;
	default:
	    printf("Color not found\n");
	    break;
    }
}
