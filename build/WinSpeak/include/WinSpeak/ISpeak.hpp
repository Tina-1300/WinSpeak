#pragma once

namespace WinSpeak{

    class ISpeak{
        public:
            [[nodiscard]] virtual float get_volume() const = 0;
            virtual bool set_volume(float volume) = 0;

            [[nodiscard]] virtual bool is_muted() const = 0;
            virtual bool set_mute(bool mute) = 0;

            virtual ~ISpeak() = default;
    };
    
}