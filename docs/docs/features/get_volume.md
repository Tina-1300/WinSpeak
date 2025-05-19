## Fonction : `get_volume()`

### Description

This method returns a float type which is the current speaker volume

### Settings

No parameters..


### Returned value

- returns the current speaker volume via a float type. 

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

        std::cout << "the current volume : " << speaker.get_volume() << " %" << "\n";

    }catch (const std::exception& e){
        std::cerr << "Error : " << e.what() << "\n";
    }

    return 0;
}
```