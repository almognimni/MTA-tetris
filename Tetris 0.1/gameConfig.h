#ifndef __GAME_CONFIG_H
#define __GAME_CONFIG_H
#define FOREGROUND_BLACK  (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

#include <Windows.h>
#include <conio.h> // for kbhit

class GameConfig
{
public:
    enum class Players_eKeys { p1LEFT = 'a', p1RIGHT = 'd', p1ROTATE_CLOCKWISE = 's', p1ROTATE_COUNTERCLOCKWISE = 'w', p1DROP = 'x',
							   p2LEFT = 'j', p2RIGHT = 'l', p2ROTATE_CLOCKWISE = 'i', p2ROTATE_COUNTERCLOCKWISE = 'k', p2DROP = 'm'};

	enum class eKeys {LEFT, RIGHT, ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE, DROP, ESC = 27 };

	static constexpr int BLOCK = 219; //The font for a block

	static constexpr int GAME_WIDTH = 12;
	static constexpr int GAME_HEIGHT = 18;

	static constexpr int MIN_X_BOARD_1 = 10;
	static constexpr int MIN_Y_BOARD_1 = 3;

	 //NEED TO CHOOSE CORD WHEN I WILL ADD THE SECOND BOARD*/
	static constexpr int MIN_X_BOARD_2 = 26;
	static constexpr int MIN_Y_BOARD_2 = 3;

	static const int COLORS[8];
	//static const int NUM_OF_COLORS;
};
#endif
