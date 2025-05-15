# 🛠️ Build

To compile this library, you will need:

- CMake

- A C++20 compiler

Compilation Steps

To compile this library, you will need Cmake and C++.

Then run these commands :

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
cmake --install .
```

After installation, you will find a WinSpeak/ folder in build/, containing:

- `include/`: Library header files

- `lib/`: Compiled binary files (.lib, .dll, etc.)

Manual Installation
Simply copy the contents of the `include/` and `lib/` folders into your development environment.

Compiling a program using WinSpeak
Example command with g++:
```bash 
g++ -O2 -Wall -Wextra -o test.exe test.cpp -lWinSpeak -lole32 -lstdc++ -luuid
```