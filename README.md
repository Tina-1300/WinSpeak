# WinSpeak

WinSpeak is a modern, powerful, and easy-to-use C++ library for controlling speakers in Windows. It allows you to manage volume, mute/unmute speakers, and query audio status simply, quickly, and securely.

## 🚀 Example Usage 

<p align="center">
    <img src="./WinSpeak_example_code.png" />
</p>

---

```cpp
#include <WinSpeak/WinSpeak.hpp>
#include <WinSpeak/AudioDeviceManager.hpp>
#include <iostream>

// g++ -O2 -Wall -Wextra -o test.exe test.cpp -lWinSpeak -lole32 -lstdc++ -luuid -lOleaut32

int main(){

    try {

        WinSpeak::AudioDeviceManager manager;

        std::vector<WinSpeak::Peripheral> devices = manager.list_devices();

        std::wcout << L"List of available audio devices :\n";

        for (size_t i = 0; i < devices.size(); ++i){

            std::wcout << L"[" << i << L"] " << devices[i].name
            << L" (ID: " << devices[i].id << L")\n";
        
        }

        std::wcout << L"\nChoose the index of the device to use (0, 1, etc.) : ";

        size_t choix;

        std::wcin >> choix;

        std::wcin.ignore();

        if (choix >= devices.size()){

            std::wcerr << L"Invalid index.\n";

            return 1;

        }

        if (!manager.set_device_by_id(devices[choix].id)){

            std::wcerr << L"Unable to select device.\n";

            return 1;

        }

        WinSpeak::WinSpeak speaker(&manager);

        if (speaker.is_muted()){

            speaker.set_mute(false);

            speaker.set_volume(100.0f);
        }

        std::wcout << L"\npress (enter) to continue\n";

        std::wcin.get();

        std::wcout << L"Current volume: " << speaker.get_volume() << "%\n";

        std::wcout << L"Mute activation...\n";

        speaker.set_mute(true);

        std::wcout << L"\npress (enter) to exit\n";

        std::wcin.get();

    }catch (const std::exception& e){

        std::wcerr << L"Error : " << e.what() << "\n";

    }

    return 0;

}
```

<br>

## 📚 WinSpeak documentation website

[https://tina-1300.github.io/documentation/WinSpeak/index.html](https://tina-1300.github.io/documentation/WinSpeak/index.html)

## 📢 WinSpeak Announcements

[https://tina-1300.github.io/documentation/Announcement-WinSpeak/Announcement-WinSpeak.html](https://tina-1300.github.io/documentation/Announcement-WinSpeak/Announcement-WinSpeak.html)

## 🌟 Support the project

>🚀 This project is under active development. If you like it, consider giving it a ⭐ to support its evolution and encourage contributions!

