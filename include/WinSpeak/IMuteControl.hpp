#pragma once

namespace WinSpeak{
    class IMuteControl{
        public:
            virtual ~IMuteControl() = default;

            [[nodiscard]] virtual bool is_muted() const = 0;
            virtual bool set_mute(bool mute) = 0;
    };
}
