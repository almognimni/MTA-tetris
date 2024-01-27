

Right now the plan is to move all the rotations simultaniusly, but to allow to rotate only if the next rotation does not collide
When a piece is touching the ground - only the current rotation cordinates will be marked true by the board


- [x] understand board, game and game config files
- [x] Add method for a tetromino to check if a place is occupied
- [x] Add method to place a tetromino on the board if it touches true while it's lowering
- [x] Make "move" method move all the rotation, will check collition only for the active one *might assume the board checked if possible first*
- [x] Make "rotate" method, will check if the next tetromino collide before switching the active rotation (in other function before it)

- [x] For collition checks - the board needs to recive the cordinates of the current rotation blocks and check if those fields are occupied

- [x] Make a function that will give the location of a rotation

- [x] Brainstorm with maor befor making further changes

	**It seems that the board should check for the collitions**

21/01 changes:

Changed the isOverlapping to check for a specific direction (TODO - need to include rotations as well)
Made "Place tetromino function"
Made "MoveCurrentTetromino" function on board (includes checking and printing) and returns true if placed
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
- [x] Set lose condition - after a new tetromino is generated, check if it's overlapping something else in the board
- [x] initiate random seed when program starts
- [x] fix tetrominoes being being stuck in the middle
- [x] make it so the game dosn't run in the menu
### optional
- [ ] consider to add bonues features:
	- [x] tetris logo
	- [x] colors
	- [x] colored menu? logo?
	- [ ] varaible speed
	- [ ] scoreboard

## Changes
Fixed the wrong tetromino placments on the board
moved rand to general, initiated seed on tetrisGame
updated the starting point in the tetromino constructor to use 'BoardWidth'
Added colors
Added colored logo

## Needs fixing
- [x] delete line (figure out the exact problem)
- [x] after a line is deleted tetrominoes may sink into each other

## 22/01 menu changing
made a tetris game constructor to handle menu, game and pausing
created enum "GameState" to be used by the game constructor before calling the game\menu functions
added reset function to: game, player, board function for starting a new game (accecible if paused)
moved tetrominoFalling to the board class and changed the functions respectivly
moved variables contaning current game state out of the start game function
handled all invalid choices
changed const BLOCK to constexplr and moved to "TetrisGame.h" file

## 23/01
removed logo and show menu from main

### implementing multiplayer
adding the second player enum keys
using a function to convert the recived char to lowercase

- [x] Need to think of a way to use the same fucntions with the different player charecters
- [x] implement maor's print board function for resuming a paused game
- [x] add instructions
- [x] add second player
- [x] add a post game screen (optional)
- [x] move some helper functions to private

added enum keys per player and removed the values for the "general keys"
added ID's for player and board
made an input handle function for player which will move the tetrominoes for the correct player by key pressed
made function to check if someopne lost and set their alive status to false
made the print tetromino function have a default value to print block and removed arg from play function
inserted maor's line deletion functions and variable to a board function
made a post game screen
changed the game loop

The game is now fully functional in multiplayer!

*** color toggle makes it so line deletion is not working ***

fixed the line deletion bug.
made it so it won't be possible to switch colors midgame
adjusted the location to delete tetromino
added comments 

fixed the menu bug that accured when entered a letter