# GameSystem
Just a mixture of SFML, TGUI, EnTT, and Box2d.
with some spice.

## Frequent Compile Error Cause
 - Haven't included needed-to-be-compiled in script/makefile
 - Haven't included needed header in script/makefile

## How to compile
### Deprecated
```make -f script/makefile [-j(how many jobs at once)]```
increasing -j parameter should decrease compile time

### Recommended
``` mkdir build && cd build && cmake .. && make [-j(how many jobs at once)]```
increasing -j parameter should decrease compile time

## coc.nvim - clangd
If you build the game on build/ directory, the compile_commands.json needed
by clangd will be produced in build/ directory or any directory where you
build this project.

Therefore, you need to symlink the compile_commands.json to the root of the project
(where CMakeLists.txt resides). see `ln` command for linux.

## Not-a-promise
We will make map editor or entity editor where you can place entities easily
using a GUI app.
