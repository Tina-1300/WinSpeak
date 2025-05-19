## Fonction : `is_muted()`

### Description

Returns `true` if the audio is muted, `false` if it is not muted.

### Settings

No parameters..


### Returned value

- Returns `true` if the audio is muted, `false` if it is not muted.

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

        std::cout << "Audio muted : " << (speaker.is_muted() ? "yes" : "no") << "\n";

    }catch (const std::exception& e){
        std::cerr << "Error : " << e.what() << "\n";
    }

    return 0;
}
```