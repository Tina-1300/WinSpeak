## Fonction : `set_volume()`

### Description

The volume to define must be a number between 0.0f and 100.0f (inclusive).

### Settings
| Parameter name   | Type      | Description                              |
|------------------|-----------|------------------------------------------|
| `volume`         | `float`   |  float value to adjust speaker volume    |


### Returned value

- Returns `true` if the volume was correctly modified, `false` in case of error.

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

        std::cout << (speaker.set_volume(100.0f) ? "Speaker 100%" : "An error has occurred" ) << "\n";

    }catch (const std::exception& e){
        std::cerr << "Error : " << e.what() << "\n";
    }

    return 0;
}
```