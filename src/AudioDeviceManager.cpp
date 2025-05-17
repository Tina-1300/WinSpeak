#include "../include/WinSpeak/AudioDeviceManager.hpp"
#include <mmdeviceapi.h>
#include <stdexcept>
#include <windows.h>

namespace WinSpeak {

    AudioDeviceManager::AudioDeviceManager() : endpointVolume(nullptr){
        CoInitialize(nullptr);

        IMMDeviceEnumerator* deviceEnumerator = nullptr;
        HRESULT hr = CoCreateInstance(
            __uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL,
            __uuidof(IMMDeviceEnumerator), (void**)&deviceEnumerator);

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
            __uuidof(IAudioEndpointVolume), CLSCTX_ALL, nullptr, (void**)&endpointVolume);
        defaultDevice->Release();

        if (FAILED(hr) || !endpointVolume){
            throw std::runtime_error("Failed to activate endpoint volume.");
        }
    }

    AudioDeviceManager::~AudioDeviceManager(){
        if (endpointVolume) endpointVolume->Release();
        CoUninitialize();
    }

    IAudioEndpointVolume* AudioDeviceManager::get_endpoint() const{
        return endpointVolume;
    }

}
