#pragma once
#include "IAudioProvider.hpp"
#include "IAudioDeviceEnumerator.hpp"

namespace WinSpeak{

    class AudioDeviceManager : public IAudioProvider, IAudioDeviceEnumerator{
    public:

        AudioDeviceManager();
        
        ~AudioDeviceManager() override;

        IAudioEndpointVolume* get_endpoint() const override;

        std::vector<Peripheral> list_devices() const override;

        bool set_device_by_id(const std::wstring& device_id) override;

    private:
        IAudioEndpointVolume* endpointVolume;
    };
    
}