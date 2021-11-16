#ifndef __CSLEEPSCREEN_H__
#define __CSLEEPSCREEN_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

enum colorName
{
	BLACK, D_BLUE, D_GREEN, D_SKYBLUE,	// 0,	1,  2,  3
	D_RED, D_VIOLET, D_YELLOW, GRAY,	// 4,	5,  6,  7
	D_GRAY, BLUE, GREEN, SKYBLUE,		// 8,	9, 10, 11
	RED, VIOLET, YELLOW, WHITE			// 12, 13, 14, 15
};

int color(int bgColor, int textColor);
int putColor(int _color);
int gotoxy(int x, int y);
void CursorView(int show);
void fullScreen();

#endif