# GameOfLife
My implementation of Conway's Game Of Life in C using GLFW and GLEW.

## Settings
You can edit game settings in file `settings.h`:
* The board has `BOARD_WIDTH`x`BOARD_HEIGHT` dimensions.
* The renderer has `WINDOW_WIDTH`x`WINDOW_HEIGHT` dimensions.
* `FULLSCREEN` is self explainatory... Be aware that you should only activate it when the board matches your screen res, especially when you use tilling window manager (as i3).
* `DEAD` and `ALIVE` are Cell's color depending on wether it's alive or not. They are RGB hex values written as integer `0x00RRGGBB` with `00` being black and `FF` being white.
