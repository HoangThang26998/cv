#pragma once
#include <juce_audio_basics/juce_audio_basics.h>

class SmartKeyLift
{
public:
    SmartKeyLift() {}

    void update(float currentPositionInSeconds, float totalLengthInSeconds)
    {
        // Kiểm tra nếu bài hát gần kết thúc (ví dụ 30 giây cuối hoặc 10% cuối)
        if (totalLengthInSeconds > 0 && currentPositionInSeconds > totalLengthInSeconds * 0.9f)
        {
            if (!hasLifted)
            {
                triggerKeyLift();
                hasLifted = true;
            }
        }
    }

    void triggerKeyLift()
    {
        // Tăng tông lên 1 bán âm (semitone)
        currentTransposeSemitones += 1;
        // Gửi lệnh MIDI/IPC sang Auto-Tune
        sendNewKeyToAutoTune();
    }

    void sendNewKeyToAutoTune()
    {
        // Logic gửi MIDI CC hoặc Inter-Plugin Communication
    }

private:
    bool hasLifted = false;
    int currentTransposeSemitones = 0;
};
