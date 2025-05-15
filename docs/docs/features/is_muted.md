## Fonction : `is_muted()`

### Description

Returns `true` if the audio is muted, `false` if it is not muted.

### Settings

No parameters..


### Returned value

- Returns `true` if the audio is muted, `false` if it is not muted.

### Example of use
```cpp
#include <iostream>
#include <WinSpeak/WinSpeak.hpp> 

int main(){

    WinSpeak::WinSpeak s;

    if(s.is_muted()){
        std::cout << "Speaker is muted" << "\n";
    }else{
        std::cout << "Speaker is unmuted" << "\n";
    }

    return 0;
}
```