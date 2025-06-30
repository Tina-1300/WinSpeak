#include "WinSpeak/WinSpeak.hpp"
#include "WinSpeak/AudioDeviceManager.hpp"
#include <iostream>

// g++ -std=c++20 -O2 -Wall -Wextra -o test.exe test.cpp -lWinSpeak -lole32 -lstdc++ -luuid

int main(){

    try {
        WinSpeak::AudioDeviceManager manager;
        WinSpeak::WinSpeak speaker(&manager);

        if (speaker.is_muted()){
            speaker.set_mute(false);
            speaker.set_volume(100.0f);
        }

        std::cout << "press (enter) to continute" << "\n";
        std::cin.get();

        std::cout << speaker.get_volume() << "\n";
        std::cout << "activate mute" << "\n";

        speaker.set_mute(true);

        std::cout << "press (enter) to exit" << "\n";
        std::cin.get();

    }catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << "\n";
    }

};