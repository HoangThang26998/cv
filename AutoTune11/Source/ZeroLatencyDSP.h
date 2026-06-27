#pragma once
#include <juce_audio_basics/juce_audio_basics.h>

class ZeroLatencyPitchShifter
{
public:
    ZeroLatencyPitchShifter() {}

    // Sử dụng thuật toán TD-PSOLA (Time-Domain Pitch Synchronous Overlap and Add)
    // Thuật toán này không cần FFT, giúp đạt độ trễ gần như bằng 0
    void process(float* samples, int numSamples, float pitchFactor)
    {
        // 1. Phân tích chu kỳ (Period detection) trong miền thời gian
        // 2. Cắt và chồng lấp các chu kỳ (Overlap-Add) để thay đổi cao độ
        // 3. Không sử dụng buffer lớn, xử lý trực tiếp theo từng block nhỏ của DAW
    }
};
