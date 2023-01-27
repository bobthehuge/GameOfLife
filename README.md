# GameOfLife
My implementation of Conway's Game Of Life in C using GLFW and GLEW

## Settings
You can edit game settings in file `game.h`:
* The board has `WIDTH` x `HEIGHT` dimensions
* `FULLSCREEN` is self explainatory... Be aware that you should only activate it when the board matches your screen res, especially when you use tilling window manager (as i3)
* `DEAD` and `ALIVE` are Cell's color depending on wether it's alive or not. They are RGB hex values written as integer `0x00RRGGBB` with `00` being black and `FF` being white.
