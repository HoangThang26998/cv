#pragma once
#include <juce_audio_basics/juce_audio_basics.h>
#include <vector>

class HarmonyVoice
{
public:
    HarmonyVoice() {}
    void process(juce::AudioBuffer<float>& input, float interval)
    {
        // Thực hiện pitch shifting dựa trên interval (ví dụ: quãng 3, quãng 5)
        // Sử dụng PSOLA để giữ chất lượng giọng hát
    }
};

class HarmonyPlayer
{
public:
    HarmonyPlayer() : voices(4) {}

    void process(juce::AudioBuffer<float>& buffer)
    {
        if (!isEnabled) return;

        juce::AudioBuffer<float> harmonyBuffer(buffer.getNumChannels(), buffer.getNumSamples());
        harmonyBuffer.clear();

        for (int i = 0; i < 4; ++i)
        {
            if (voiceActive[i])
            {
                // Tạo bản sao tín hiệu và dịch chuyển tông
                voices[i].process(buffer, voiceIntervals[i]);
                // Mix vào harmonyBuffer
            }
        }
        
        // Mix harmonyBuffer ngược lại vào buffer chính
    }

    void setVoiceInterval(int index, float semitones) { voiceIntervals[index] = semitones; }
    void setEnabled(bool state) { isEnabled = state; }

private:
    bool isEnabled = true;
    std::vector<HarmonyVoice> voices;
    float voiceIntervals[4] = { -12.0f, -5.0f, 4.0f, 7.0f }; // Ví dụ các quãng bè
    bool voiceActive[4] = { true, true, true, true };
};
