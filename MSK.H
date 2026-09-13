#ifndef MSK                                                    //version 0.3
#define MSK

#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <direct.h>
#include <assert.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


// Macros
#define pf printf
#define sf scanf
#define cls clrscr
#define cld cleardevice
#define rect rectangle
#define otxy outtextxy
#define spf sprintf

#define x 639 // graphics window height and width
#define y 479


#define BACKSPACE 8  
#define ENTER 13  
#define ESCAPE 27  

#define AK_LEFT 75
#define AK_RIGHT 77
#define AK_UP 72
#define AK_DOWN 80
#define IS_AK 0

#define SQ(a) ((a)*(a))
#define CUBE(a) ((a)*(a)*(a))

#define PI 3.14159265358979323846

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))


// Text colors
#define TEXT_BLACK       "\033[30m"
#define TEXT_RED         "\033[31m"
#define TEXT_GREEN       "\033[32m"
#define TEXT_YELLOW      "\033[33m"
#define TEXT_BLUE        "\033[34m"
#define TEXT_MAGENTA     "\033[35m"
#define TEXT_CYAN        "\033[36m"
#define TEXT_WHITE       "\033[37m"
#define TEXT_B_BLACK     "\033[90m"
#define TEXT_B_RED       "\033[91m"
#define TEXT_B_GREEN     "\033[92m"
#define TEXT_B_YELLOW    "\033[93m"
#define TEXT_B_BLUE      "\033[94m"
#define TEXT_B_MAGENTA   "\033[95m"
#define TEXT_B_CYAN      "\033[96m"
#define TEXT_B_WHITE     "\033[97m"

// BG colors
#define BG_BLACK         "\033[40m"
#define BG_RED           "\033[41m"
#define BG_GREEN         "\033[42m"
#define BG_YELLOW        "\033[43m"
#define BG_BLUE          "\033[44m"
#define BG_MAGENTA       "\033[45m"
#define BG_CYAN          "\033[46m"
#define BG_WHITE         "\033[47m"
#define BG_B_BLACK       "\033[100m"
#define BG_B_RED         "\033[101m"
#define BG_B_GREEN       "\033[102m"
#define BG_B_YELLOW      "\033[103m"
#define BG_B_BLUE        "\033[104m"
#define BG_B_MAGENTA     "\033[105m"
#define BG_B_CYAN        "\033[106m"
#define BG_B_WHITE       "\033[107m"

// Text attributes
#define RESET            "\033[0m"
#define BOLD             "\033[1m"
#define DIM              "\033[2m"
#define ITALIC           "\033[3m"
#define UNDERLINE        "\033[4m"
#define _BLINK           "\033[5m"
#define REVERSE          "\033[7m"
#define CONCEAL          "\033[8m"
#define CROSSED_OUT      "\033[9m"
#define DOUBLE_UNDERLINE "\033[21m"
#define NORMAL_INTENSITY "\033[22m"
#define NOT_ITALIC       "\033[23m"
#define NOT_UNDERLINED   "\033[24m"
#define NOT_BLINKING     "\033[25m"
#define POSITIVE_VIDEO   "\033[27m"
#define REVEALED         "\033[28m"
#define NOT_CROSSED_OUT  "\033[29m"



void fill(int left, int up, int right, int down, int patt, int color)
{
    setfillstyle(patt,color);
    bar(left,up,right,down);
}

void re(int left, int up, int right, int down, int color)
{
    setcolor(color);
    rect(left,up,right,down);
}

void txt(int X, int Y, int color, int font, int dir, int size, char text[])
{
    setcolor(color);
    settextstyle(font,dir,size);
    otxy(X,Y,text);
}



#endif