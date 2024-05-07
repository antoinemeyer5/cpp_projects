#!/bin/bash

echo '- Build START -'

# compile wxWidgets
mkdir build_wx && cd build_wx
cmake ../../wxWidgets
make -j 16
cd ..
echo '- Compile 1/2 -'

# compile src
mkdir build_src && cd build_src
clang++ -std=c++17 `../build_wx/wx-config --cxxflags` ../../src/*.cpp -o exec `../build_wx/wx-config --libs`
cd ..
echo '- Compile 2/2 -'

echo '- Build END -'
