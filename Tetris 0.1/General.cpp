#include "General.h"

using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void clrscr()
{
	system("cls");
}

void maximizeConsole()
{
	HWND consoleWindow = GetConsoleWindow();  // Get a handle to the console window

	// Get the current screen width and height
	RECT screenRect;
	GetWindowRect(GetDesktopWindow(), &screenRect);

	// Resize the console window to the current screen width and height
	MoveWindow(consoleWindow, 0, 0, screenRect.right, screenRect.bottom, TRUE);
}