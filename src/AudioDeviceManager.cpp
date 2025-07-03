#include "../include/WinSpeak/AudioDeviceManager.hpp"
#include <mmdeviceapi.h>
#include <stdexcept>
#include <windows.h>
#include <initguid.h>
#include <functiondiscoverykeys_devpkey.h>


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

    std::vector<Peripheral> AudioDeviceManager::list_devices() const{

        std::vector<Peripheral> devices;

        IMMDeviceEnumerator* enumerator = nullptr;

        if (FAILED(CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr,
            CLSCTX_ALL, IID_PPV_ARGS(&enumerator)))){

            return devices;

        }

        IMMDeviceCollection* collection = nullptr;

        if (FAILED(enumerator->EnumAudioEndpoints(eRender, DEVICE_STATE_ACTIVE, &collection))){
            
            enumerator->Release();

            return devices;

        }

        UINT count = 0;

        collection->GetCount(&count);

        for (UINT i = 0; i < count; ++i){

            IMMDevice* device = nullptr;

            if (FAILED(collection->Item(i, &device))){continue;}

            LPWSTR id = nullptr;

            device->GetId(&id);

            IPropertyStore* props = nullptr;

            device->OpenPropertyStore(STGM_READ, &props);

            PROPVARIANT name;

            PropVariantInit(&name);

            props->GetValue(PKEY_Device_FriendlyName, &name);

            devices.emplace_back(id, name.pwszVal);

            CoTaskMemFree(id);

            PropVariantClear(&name);

            props->Release();

            device->Release();

        }

        return devices; 
    
    }

    bool AudioDeviceManager::set_device_by_id(const std::wstring& device_id){

        IMMDeviceEnumerator* enumerator = nullptr;

        if (FAILED(CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, 
            CLSCTX_ALL, IID_PPV_ARGS(&enumerator)))){

            return false;

        }

        IMMDevice* device = nullptr;

        if (FAILED(enumerator->GetDevice(device_id.c_str(), &device))){

            enumerator->Release();

            return false;

        }

        IAudioEndpointVolume* newEndpoint = nullptr;

        if (FAILED(device->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL,
            nullptr, (void**)&newEndpoint))){

            device->Release();

            enumerator->Release();

            return false;

        }

        if (endpointVolume){endpointVolume->Release();}

        endpointVolume = newEndpoint;

        device->Release();

        enumerator->Release();

        return true;
        
    }

}