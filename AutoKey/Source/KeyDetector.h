#pragma once
#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_dsp/juce_dsp.h>
#include <vector>
#include <cmath>

class KeyDetector
{
public:
    KeyDetector() : fft(11) // 2048 points
    {
        chroma.assign(12, 0.0f);
    }

    void processBlock(const juce::AudioBuffer<float>& buffer, double sampleRate)
    {
        // 1. Phân tích phổ (FFT)
        // 2. Chuyển đổi sang Chromagram (12 nốt)
        // 3. So khớp với profile của các tông (Major/Minor)
        
        // Đây là bản mô phỏng logic dò tông
        auto* channelData = buffer.getReadPointer(0);
        int numSamples = buffer.getNumSamples();
        
        // Tích lũy năng lượng cho 12 nốt (giả lập đơn giản)
        for (int i = 0; i < numSamples; ++i)
        {
            // Phân tích tần số ở đây...
        }
    }

    juce::String getDetectedKey() const { return detectedKey; }
    juce::String getDetectedScale() const { return detectedScale; }

private:
    juce::dsp::FFT fft;
    std::vector<float> chroma;
    juce::String detectedKey = "C";
    juce::String detectedScale = "Major";
};
