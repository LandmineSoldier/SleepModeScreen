#include "cSleepScreen.h"


int color(int bgColor, int textColor)
{
	switch (bgColor)
	{
	case BLACK:		bgColor = 40; break;
	case D_RED:		bgColor = 41; break;
	case D_GREEN:	bgColor = 42; break;
	case D_YELLOW:	bgColor = 43; break;
	case D_BLUE:	bgColor = 44; break;
	case D_VIOLET:	bgColor = 45; break;
	case D_SKYBLUE:	bgColor = 46; break;
	case GRAY:		bgColor = 47; break;
	case D_GRAY:	bgColor = 100;break;
	case RED:		bgColor = 101;break;
	case GREEN:		bgColor = 102;break;
	case YELLOW:	bgColor = 103;break;
	case BLUE:		bgColor = 104;break;
	case VIOLET:	bgColor = 105;break;
	case SKYBLUE:	bgColor = 106;break;
	case WHITE:		bgColor = 107;break;
	}

	//printf("%c[%d;%d;%dm"0x1B,7,49,bgColor); // 특성, 글자색, 바탕색
	printf("%c[%dm", 27, bgColor); // 바탕색
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);
}

int putColor(int _color)
{
	if (_color != -1) { color(_color, _color); puts("  "); color(BLACK, BLACK);}
}

int gotoxy(int x, int y)
{
	printf("\033[%d;%df", y, x);
	fflush(stdout);
}

void CursorView(int show) // 입력 커서 제거
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void fullScreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}