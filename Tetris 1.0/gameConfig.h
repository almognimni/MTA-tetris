/**
 * @file gameConfig.h
 * @brief Game configuration constants and settings
 * 
 * This file contains all game configuration parameters including board dimensions,
 * input key mappings, positioning constants, and color definitions. These values
 * control the core gameplay mechanics and visual layout.
 */

#ifndef __GAME_CONFIG_H
#define __GAME_CONFIG_H
#define FOREGROUND_BLACK  (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

#include <Windows.h>
#include <conio.h> // for kbhit

/**
 * @brief Central configuration class containing game constants and settings
 * 
 * GameConfig provides static constants and enumerations that define the game's
 * behavior, dimensions, controls, and visual properties. All values are
 * compile-time constants for performance.
 */
class GameConfig
{
public:
	/**
	 * @brief Enumeration of player input keys
	 * 
	 * Defines the keyboard controls for player actions during gameplay.
	 */
	enum class eKeys { 
		LEFT = 'a',                    ///< Move piece left
		RIGHT = 'd',                   ///< Move piece right  
		ROTATE_CLOCKWISE = 's',        ///< Rotate piece clockwise
		ROTATE_COUNTERCLOCKWISE = 'w', ///< Rotate piece counter-clockwise
		DROP = 'x',                    ///< Drop piece quickly
		ESC = 27                       ///< Escape key (pause/menu)
	};
	
	/** @brief Width of the game board in blocks */
	static constexpr int GAME_WIDTH = 12;
	
	/** @brief Height of the game board in blocks */
	static constexpr int GAME_HEIGHT = 18;

	/** @brief Minimum X coordinate for player 1's board display */
	static constexpr int MIN_X_BOARD_1 = 10;
	
	/** @brief Minimum Y coordinate for player 1's board display */
	static constexpr int MIN_Y_BOARD_1 = 3;

	/** 
	 * @brief Reserved coordinates for player 2's board (future multiplayer support)
	 * 
	 * These constants are commented out but reserved for when
	 * multiplayer functionality is implemented.
	 */
	//static constexpr int MIN_X_BOARD_2 = 10;
	//static constexpr int MIN_Y_BOARD_2 = 3;

	/** @brief Array of color codes for different piece types */
	static const int COLORS[8];
	//static const int NUM_OF_COLORS; // Currently unused
};
#endif
