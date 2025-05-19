## Fonction : `set_mute()`

### Description

allows you to change the current state of the speaker to either mute or unmute it

### Settings
| Parameter name   | Type      | Description                              |
|------------------|-----------|------------------------------------------|
| `mute`           | `bool`      |   A boolean value. Pass true to mute the audio, or false to unmute it. |


### Returned value

- Returns `true` if the mute status was successfully set, `false` in case of an error.

### Example of use
```cpp
#include <WinSpeak/WinSpeak.hpp>
#include <WinSpeak/AudioDeviceManager.hpp>
#include <iostream>

// g++ -O2 -Wall -Wextra -o test.exe test.cpp -lWinSpeak -lole32 -lstdc++ -luuid


int main(){

    try {
        WinSpeak::AudioDeviceManager manager;
        WinSpeak::WinSpeak speaker(&manager);

        std::cout << "press enter to continue" << "\n";
        std::cin.get();

        if(speaker.set_mute(true)){
            std::cout << "Speaker muted" << "\n";
        }

        std::cout << "press enter to continue" << "\n";
        std::cin.get();

        if(speaker.set_mute(false)){
            std::cout << "Speaker unmuted" << "\n";
        }

        std::cout << "press enter to exit" << "\n";
        std::cin.get();

    }catch (const std::exception& e){
        std::cerr << "Error : " << e.what() << "\n";
    }

    return 0;
}
```