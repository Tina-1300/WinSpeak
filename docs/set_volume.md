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
#include <iostream>
#include <WinSpeak/WinSpeak.hpp> 

int main(){

    WinSpeak::WinSpeak s;

    if(s.set_volume(100.0f)){
        std::cout << "Speaker 100%" << "\n";
    }else{
        std::cout << "An error has occurred" << "\n";
    }

    return 0;
}
```