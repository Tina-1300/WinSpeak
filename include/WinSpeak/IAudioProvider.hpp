#pragma once
#include <endpointvolume.h>

namespace WinSpeak{

    class IAudioProvider{
        public:
            virtual ~IAudioProvider() = default;
            virtual IAudioEndpointVolume* get_endpoint() const = 0;
    };

}