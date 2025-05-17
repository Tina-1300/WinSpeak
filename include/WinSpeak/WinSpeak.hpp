#pragma once
#include "IVolumeControl.hpp"
#include "IMuteControl.hpp"
#include "IAudioProvider.hpp"

namespace WinSpeak{

    class WinSpeak : public IVolumeControl, IMuteControl{
        public: 
            explicit WinSpeak(IAudioProvider* provider);
            ~WinSpeak() override = default;

            /*
            No parameters..
            Returns the current volume.
            */
            [[nodiscard]] float get_volume() const override;
            
            /*
            The volume to define must be a number between 0.0f and 100.0f (inclusive).
            Returns `true` if the volume was correctly modified, `false` in case of error.
            */
           bool set_volume(float volume) override;

            /*
            No parameters..
            Returns `true` if the audio is muted, `false` if it is not muted.
            */
           [[nodiscard]] bool is_muted() const override;

            /*
            A boolean value. Pass true to mute the audio, or false to unmute it.
            Returns `true` if the mute status was successfully set, `false` in case of an error.
            */
           bool set_mute(bool mute) override;

        private:
            IAudioEndpointVolume* endpointVolume;
    };
    
}