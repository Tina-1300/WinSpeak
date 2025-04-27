## Fonction : `get_volume()`

### Description

This method returns a float type which is the current speaker volume

### Settings

No parameters..


### Returned value

- returns the current speaker volume via a float type. 

### Example of use
```cpp
#include <iostream>
#include <WinSpeak/WinSpeak.hpp> 

int main(){

    WinSpeak::WinSpeak s;

    std::cout << "the current volume : " << s.get_volume() << " %" << "\n";

    return 0;
}
```