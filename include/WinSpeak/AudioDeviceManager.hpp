#pragma once
#include "IAudioProvider.hpp"

namespace WinSpeak{

    class AudioDeviceManager : public IAudioProvider{
    public:
        AudioDeviceManager();
        ~AudioDeviceManager() override;

        IAudioEndpointVolume* get_endpoint() const override;

    private:
        IAudioEndpointVolume* endpointVolume;
    };

}
