#include "cSleepScreen.h"

int main(void)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int winSizeX, winSizeY, pointX = 1, pointY = 1;
	int preWinSizeX = 0, preWinSizeY = 0;
	int xFlag = 0, yFlag = 0;
	int xPlus = 1, yPlus = 1;
	int pointColor = D_BLUE;

	srand((unsigned int)time(NULL));
	system("mode con:lines=50  cols=50");
	pointX = rand() % 48 + 1;
	pointY = rand() % 48 + 1;

	while (1)
	{
		CursorView(0);
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		winSizeX = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		winSizeY = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
		if (winSizeX != preWinSizeX || winSizeY != preWinSizeY)
			system("cls");

		gotoxy(pointX, pointY);
		putColor(pointColor);

		Sleep(25);

		preWinSizeX = winSizeX;
		preWinSizeY = winSizeY;

		gotoxy(pointX, pointY);
		putColor(BLACK);

		if (xFlag == 0)
		{
			pointX += xPlus;
			if (pointX >= winSizeX - xPlus)
			{
				xFlag = 1;
				xPlus = rand() % 3 + 1;

				if (pointColor != WHITE)
					pointColor++;
				else if (pointColor == WHITE)
					pointColor = D_BLUE;
			}
		}
		else if (xFlag == 1)
		{
			pointX -= xPlus;
			if (pointX <= 0 + xPlus)
			{
				xFlag = 0;
				xPlus = rand() % 3 + 1;

				if (pointColor != WHITE)
					pointColor++;
				else if (pointColor == WHITE)
					pointColor = D_BLUE;
			}
		}

		if (yFlag == 0)
		{
			pointY += yPlus;
			if (pointY >= winSizeY - yPlus)
			{
				yFlag = 1;
				yPlus = rand() % 3 + 1;

				if (pointColor != WHITE)
					pointColor++;
				else if (pointColor == WHITE)
					pointColor = D_BLUE;
			}
		}
		else if (yFlag == 1)
		{
			pointY -= yPlus;
			if (pointY <= 0 + yPlus)
			{
				yFlag = 0;
				yPlus = rand() % 3 + 1;

				if (pointColor != WHITE)
					pointColor++;
				else if (pointColor == WHITE)
					pointColor = D_BLUE;
			}
		}
	}
}