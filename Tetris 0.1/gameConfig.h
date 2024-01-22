#ifndef __GAME_CONFIG_H
#define __GAME_CONFIG_H
#define FOREGROUND_BLACK  (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

#include <Windows.h>
#include <conio.h> // for kbhit

class GameConfig
{
public:
	enum class eKeys { LEFT = 'a', RIGHT = 'd', ROTATE_CLOCKWISE = 's', ROTATE_COUNTERCLOCKWISE = 'w', DROP = 'x', ESC = 27 };
	static constexpr int GAME_WIDTH = 12;
	static constexpr int GAME_HEIGHT = 18;

	static constexpr int MIN_X_BOARD_1 = 10;
	static constexpr int MIN_Y_BOARD_1 = 3;

	/* NEED TO CHOOSE CORD WHEN I WILL ADD THE SECOND BOARD*/
	//static constexpr int MIN_X_BOARD_2 = 10;
	//static constexpr int MIN_Y_BOARD_2 = 3;

	static const int COLORS[8];
	//static const int NUM_OF_COLORS;
};
#endif
