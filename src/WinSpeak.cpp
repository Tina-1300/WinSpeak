#include "../include/WinSpeak/WinSpeak.hpp"
#include <windows.h>
#include <mmdeviceapi.h>
#include <stdexcept>


namespace WinSpeak{

    WinSpeak::WinSpeak() : endpointVolume(nullptr){
        initialize();
    };

    WinSpeak::~WinSpeak(){
        if (endpointVolume){
            endpointVolume->Release();
        }
        CoUninitialize();
    }

    float WinSpeak::get_volume() const {
        float currentVolume = 0.0f;
        HRESULT hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
        if (FAILED(hr)){
            throw std::runtime_error("Failed to get current volume level.");
        }
        return currentVolume * 100; 
    }

    bool WinSpeak::set_volume(float volume){
        if (volume < 0.0f || volume > 100.0f){
            throw std::invalid_argument("Volume must be between 0 and 100.");
            return false;
        }
        HRESULT hr = endpointVolume->SetMasterVolumeLevelScalar(volume / 100.0f, nullptr);
        if (FAILED(hr)){
            return false; // Failed to set volume level.
        }
        return true;
    }

    bool WinSpeak::is_muted() const {
        BOOL isMuted = FALSE;
        HRESULT hr = endpointVolume->GetMute(&isMuted);
        if (FAILED(hr)){
            throw std::runtime_error("Failed to get mute status.");
        }
        return isMuted;
    }

    bool WinSpeak::set_mute(bool mute){
        HRESULT hr = endpointVolume->SetMute(mute, nullptr);
        return (FAILED(hr)) ? (
            false // Failed to set mute status.
        ) : true;
    }

    
    void WinSpeak::initialize(){
        CoInitialize(nullptr);

        IMMDeviceEnumerator* deviceEnumerator = nullptr;
        HRESULT hr = CoCreateInstance(
            __uuidof(MMDeviceEnumerator),
            nullptr,
            CLSCTX_ALL,
            __uuidof(IMMDeviceEnumerator),
            (void**)&deviceEnumerator);

        if (FAILED(hr) || !deviceEnumerator){
            throw std::runtime_error("Failed to create device enumerator.");
        }

        IMMDevice* defaultDevice = nullptr;
        hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
        deviceEnumerator->Release();

        if (FAILED(hr) || !defaultDevice){
            throw std::runtime_error("Failed to get default audio endpoint.");
        }

        hr = defaultDevice->Activate(
            __uuidof(IAudioEndpointVolume),
            CLSCTX_ALL,
            nullptr,
            (void**)&endpointVolume);
        defaultDevice->Release();

        if (FAILED(hr) || !endpointVolume){
            throw std::runtime_error("Failed to activate audio endpoint.");
        }
    };

}