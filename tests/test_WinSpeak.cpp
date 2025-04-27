#include <iostream>
#include "WinSpeak/WinSpeak.hpp"

// g++ -O2 -Wall -Wextra -o test.exe test.cpp -lWinSpeak -lole32 -lstdc++ -luuid


int main(){

    WinSpeak::WinSpeak s;

    if(s.is_muted()){
        s.set_mute(false);
        s.set_volume(100.0f);
    }

    std::cout << s.get_volume() << "\n";

    std::cin.get();
};