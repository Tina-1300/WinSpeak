# WinSpeak

WinSpeak is a modern, powerful, and easy-to-use C++ library for controlling speakers in Windows. It allows you to manage volume, mute/unmute speakers, and query audio status simply, quickly, and securely.



## 📚 Introduction

Why use WinSpeak ?

Save time: Easily manage speakers in Windows without diving into the complexities of low-level API.

Simplicity: Clean and intuitive interface to focus on what matters most.

Efficiency: Optimized performance for professional or personal audio applications.

## 🎯 Project Philosophy

The philosophy behind all my projects remains the same:

Simplify the use of C++, write clean, fast, and elegant code, without having to worry about all the complexity hidden within the language.


## 🛠️ Build

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
Simply copy the contents of the include/ and lib/ folders into your development environment.

Compiling a program using WinSpeak
Example command with g++:
```bash 
g++ -O2 -Wall -Wextra -o test.exe test.cpp -lWinSpeak -lole32 -lstdc++ -luuid
```

## 📄 Documentation utile

- [CHANGELOG.md](CHANGELOG.md) - Version history
- [CONTRIBUTING.md](CONTRIBUTING.md) – How to contribute to the project
- [ROADMAP.md](ROADMAP.md) – Future development plan
- [FAQ.md](FAQ.md) – Frequently Asked Questions
- [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) - Rules of Conduct
- [WinSpeak.md](docs/WinSpeak.md) - documentation of functions, classes of the library  
