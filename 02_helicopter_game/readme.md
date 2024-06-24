# Helicopter game

## Abstract

The goal of the game is to drive the helicopter and kill enemies.

## How to

```bash
# compile
02_helicopter_game % git clone --recurse-submodules https://github.com/wxWidgets/wxWidgets.git
02_helicopter_game % mkdir build && cd build
build % source ../build.sh

# compile only the source
02_helicopter_game % cd build/build_src
build_src % clang++ -std=c++17 `../build_wx/wx-config --cxxflags` ../../src/*.cpp -o exec `../build_wx/wx-config --libs`

# execute
02_helicopter_game % cd build
build % ./build_src/exec

# tests
# todo
```

## Diagram

`main` has a `Frame`.
`Frame` has a `wxStatusBar` and a `Board`.
`Board` has a `Helicopter`.
