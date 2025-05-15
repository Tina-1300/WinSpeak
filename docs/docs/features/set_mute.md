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
#include <iostream>
#include <WinSpeak/WinSpeak.hpp> 

int main(){

    WinSpeak::WinSpeak s;

    if(s.set_mute(true)){
        std::cout << "Speaker muted" << "\n";
    }else{
        std::cout << "An error has occurred" << "\n";
    }

    return 0;
}
```