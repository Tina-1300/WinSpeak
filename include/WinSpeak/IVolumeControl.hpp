#pragma once

namespace WinSpeak{
    class IVolumeControl{
        public:
            virtual ~IVolumeControl() = default;

            [[nodiscard]] virtual float get_volume() const = 0;
            virtual bool set_volume(float volume) = 0;
    };
}
