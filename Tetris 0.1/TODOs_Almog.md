

Right now the plan is to move all the rotations simultaniusly, but to allow to rotate only if the next rotation does not collide
When a piece is touching the ground - only the current rotation cordinates will be marked true by the board




- [ ] understand board, game and game config files
- [ ] Add method for a function to check if a place is occupied (if the board cell has true) *might be handled by board*
- [ ] Add method to place a function on the board if it touches true while it's lowering (return true or something) *might be handled by board*
- [ ] Make "move" method move all the rotation, will check collition only for the active one *might assume the board checked if possible first*
- [ ] Make "rotate" method, will check if the next shape collide before switching the active rotation

- [ ] For collition checks - the board needs to recive the cordinates of the current rotation blocks and check if those fields are occupied
	*Might also be possible that each block will check if the board is occupied there*

- [ ] Make a function that will give the location of the current rotation (maybe by 2 arrays, one for x one for y? / maybe 2x4 array of ints, xy cord for each block?)

- [ ] Brainstorm with maor befor making further changes

	**It seems that the board should check for the collitions**

- [ ] 
- [ ] 


21/01 changes:
- [x] consider not requiering "Tetromino" parameter in the board functions (it has it in the class) 


Changed the isOverlapping to check for a specific direction (TODO - need to include rotations as well)
Made "Place tetromino function"
Made "MoveCurrentShape" function on board (includes checking and printing) and returns true if placed
Changed the board functions that operates on tetrominoes to use this instead of parameter
Working on game loop

22/01
Changed the instance of the tetromino object inside the board object to a pointer
fixed the bouneries for the check overlap
fixed some stuff in the play game loop

The basic game loop is functional!

added  a function to force full screen - not working
added a default function for isOverlapping to check the current location

## TODO's
- [x] Set lose condition - after a new shape is generated, check if it's overlapping something else in the board
- [x] initiate random seed when program starts
- [x] fix shapes being being stuck in the middle
- [ ] make it so the game dosn't run in the menu
- [ ] add support for 2 players
- [ ] try to make playerBoard private
- [ ] disable the default copy constructor for the tetrominos because of the way we use it in "Board"(?)
### optional
- [ ] consider to add bonues features:
	- [x] tetris logo
	- [x] colors
	- [x] colored menu? logo?
	- [ ] varaible speed
	- [ ] scoreboard
- [ ] consider deleting "player.cpp"

## Changes
Fixed the wrong shape placments on the board
moved rand to general, initiated seed on tetrisGame
updated the starting point in the tetromino constructor to use 'BoardWidth'
Added colors
Added colored logo

## Needs fixing
- [ ] delete line (figure out the exact problem)
- [ ] after a line is deleted shapes may sink into each other

## 22/01 menu changing
made a tetris game constructor to handle menu, game and pausing
created enum "GameState" to be used by the game constructor before calling the game\menu functions
added reset function to: game, player, board function for starting a new game (accecible if paused)
moved shapeFalling to the board class and changed the functions respectivly
moved variables contaning current game state out of the start game function
handled all invalid choices
changed const BLOCK to constexplr and moved to "TetrisGame.h" file

# For future
- [ ] try to eliminate the dynamic arrays for ex2 (consider using "vector")