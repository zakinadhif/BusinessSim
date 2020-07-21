# GameSystem
Just a mixture of SFML, TGUI, EnTT, and Box2d.
with some spice.

## How to compile
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

## Todo
- Remove `tgui::Group::Ptr TestState::thisGroup` kind of model because it can be problematic, for example if you forget to add `thisGroup = tgui::Group::create()` before you call the `add` method into it, it will produce segfault
