#ifndef __GAME_CONFIG_H
#define __GAME_CONFIG_H
#define FOREGROUND_BLACK  (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

#include <Windows.h> // for sleep and colors
#include <conio.h> // for kbhit

class GameConfig
{
public:
	// Enums for player keys and general keys
    enum class Players_eKeys { p1LEFT = 'a', p1RIGHT = 'd', p1ROTATE_CLOCKWISE = 's', p1ROTATE_COUNTERCLOCKWISE = 'w', p1DROP = 'x',
							   p2LEFT = 'j', p2RIGHT = 'l', p2ROTATE_CLOCKWISE = 'i', p2ROTATE_COUNTERCLOCKWISE = 'k', p2DROP = 'm'};

	enum class eKeys {LEFT, RIGHT, ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE, DROP, ESC = 27 };

	// Constants for block characters
	static constexpr int BLOCK = 219; //The font for a block
	static constexpr int EMPTYBOLCK = ' '; //The font for a block

	// Game board dimensions
	static constexpr int GAME_WIDTH = 12;
	static constexpr int GAME_HEIGHT = 18;

	// Minimum coordinates for the first game board
	static constexpr int MIN_X_BOARD_1 = 10;
	static constexpr int MIN_Y_BOARD_1 = 3;

	// Minimum coordinates for the second game board
	static constexpr int MIN_X_BOARD_2 = 50;
	static constexpr int MIN_Y_BOARD_2 = 3;

	// Array of colors for console text attributes
	static const int COLORS[];

};


#endif
