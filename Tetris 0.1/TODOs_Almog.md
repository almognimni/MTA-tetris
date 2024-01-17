

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

	Tasks after meeting with maor:
- [ ] Collition checks in board
- [ ] collition check for next rotation
- [ ] rotate function
- [ ] place tetromino on board
- [ ] check 