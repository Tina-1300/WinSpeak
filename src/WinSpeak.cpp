#include "../include/WinSpeak/WinSpeak.hpp"
#include <stdexcept>

namespace WinSpeak{

    WinSpeak::WinSpeak(IAudioProvider* provider) : endpointVolume(provider->get_endpoint()){
        if (!endpointVolume){
            throw std::runtime_error("Invalid endpoint volume.");
        }
    }

    float WinSpeak::get_volume() const{
        float volume = 0.0f;
        HRESULT hr = endpointVolume->GetMasterVolumeLevelScalar(&volume);
        if (FAILED(hr)){
            throw std::runtime_error("Failed to get volume.");
        }
        return volume * 100.0f;
    }

    bool WinSpeak::set_volume(float volume){
        if (volume < 0.0f || volume > 100.0f){
            throw std::invalid_argument("Volume must be between 0 and 100.");
        }

        HRESULT hr = endpointVolume->SetMasterVolumeLevelScalar(volume / 100.0f, nullptr);
        return SUCCEEDED(hr);
    }

    bool WinSpeak::is_muted() const{
        BOOL isMuted = FALSE;
        HRESULT hr = endpointVolume->GetMute(&isMuted);
        if (FAILED(hr)){
            throw std::runtime_error("Failed to get mute status.");
        }
        return isMuted;
    }

    bool WinSpeak::set_mute(bool mute){
        HRESULT hr = endpointVolume->SetMute(mute, nullptr);
        return SUCCEEDED(hr);
    }

}
