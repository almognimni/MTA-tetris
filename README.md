# MTA Tetris

A C++ implementation of the classic Tetris game for Windows console applications.

## Overview

This project is a fully functional Tetris game implemented in C++ using Windows console APIs for graphics and input handling. The game features the classic Tetris gameplay with falling tetrominoes, line clearing, and score tracking.

## Features

- **Classic Tetris Gameplay**: Seven different tetromino shapes (I, O, T, L, J, S, Z pieces)
- **Shape Rotation**: Clockwise and counter-clockwise rotation (note: counter-clockwise rotation currently has a bug)
- **Line Clearing**: Automatic detection and clearing of completed horizontal lines
- **Colored Display**: Different colors for each tetromino type
- **Menu System**: Main menu with options to start new game, continue, or exit
- **Pause Functionality**: Ability to pause and resume gameplay
- **Game Over Detection**: Automatic detection when pieces reach the top

## Controls

- **A**: Move piece left
- **D**: Move piece right  
- **S**: Rotate piece clockwise
- **W**: Rotate piece counter-clockwise
- **X**: Drop piece quickly
- **ESC**: Pause game/return to menu

## Architecture

The game is structured using object-oriented design with the following main components:

### Core Classes

- **`TetrisGame`**: Main game controller managing state transitions, menu system, and game loop
- **`Board`**: Manages the playing field, piece placement, collision detection, and line clearing
- **`Tetrominoes`**: Represents falling pieces with rotation states and movement capabilities
- **`Block`**: Individual square units that make up tetrominoes
- **`Player`**: Player state management and board ownership
- **`GameConfig`**: Configuration constants for game dimensions, controls, and colors

### Key Files

- `Main.cpp`: Application entry point
- `TetrisGame.h/.cpp`: Main game controller
- `board.h/.cpp`: Game board management
- `Tetrominoes.h/.cpp`: Tetris piece implementation
- `Block.h/.cpp`: Individual block components
- `Player.h/.cpp`: Player state management
- `gameConfig.h/.cpp`: Game configuration and constants
- `General.h/.cpp`: Utility functions for console manipulation

## Technical Details

### Dependencies
- Windows API (windows.h) for console manipulation and colors
- Standard C++ libraries (iostream, cstdlib, ctime)

### Build Requirements
- Windows operating system
- Visual Studio or compatible C++ compiler with Windows SDK
- Project files: `Tetris 0.1.vcxproj`, `MTA tetris.sln`

### Memory Management
- Dynamic allocation used for tetromino rotation states
- Automatic cleanup in destructors
- Explicit deletion of tetromino objects when placed

## Known Issues

1. **Rotation Bug**: Counter-clockwise rotation currently has the same implementation as clockwise rotation
2. **Console Maximization**: The `maximizeConsole()` function is not working properly
3. **Multiplayer**: Player 2 implementation is incomplete (reserved for future development)

## Development Status

This is a fully functional single-player Tetris implementation. The game includes:

- ✅ Complete single-player gameplay
- ✅ All seven tetromino types
- ✅ Line clearing mechanics
- ✅ Menu system and game states
- ✅ Colored graphics
- ✅ Pause/resume functionality
- ⏳ Multiplayer support (planned)
- ⏳ Post-game screen (planned)
- ⏳ Instructions screen (planned)
- ⏳ Variable speed gameplay (planned)
- ⏳ Scoreboard system (planned)

## Building and Running

1. Open `MTA tetris.sln` in Visual Studio
2. Build the solution (Ctrl+Shift+B)
3. Run the executable in a Windows console environment

Note: This project is designed specifically for Windows console applications and uses Windows-specific APIs for graphics and input handling.

## Contributing

This appears to be a student project for MTA (likely an educational institution). The codebase includes TODO comments and development notes that indicate ongoing development and learning objectives.

## License

No license information is currently provided with this project.