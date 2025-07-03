#pragma once
#include <vector>
#include <string>

namespace WinSpeak{

    struct Peripheral{
        
        std::wstring id;
        
        std::wstring name;
        
    };
    
    class IAudioDeviceEnumerator{
        public:

            virtual std::vector<Peripheral> list_devices() const = 0;

            virtual bool set_device_by_id(const std::wstring& device_id) = 0;

            virtual ~IAudioDeviceEnumerator() = default;

    };

}