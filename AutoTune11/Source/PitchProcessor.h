#pragma once
#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_dsp/juce_dsp.h>

class PitchProcessor
{
public:
    PitchProcessor() {}

    void prepare(double sampleRate, int samplesPerBlock)
    {
        this->sampleRate = sampleRate;
    }

    void process(juce::AudioBuffer<float>& buffer)
    {
        // 1. Dò cao độ hiện tại (Pitch Detection - YIN/MPM)
        // 2. Tính toán nốt mục tiêu dựa trên Key/Scale
        // 3. Chỉnh tông (Pitch Shifting - PSOLA)
        // 4. Áp dụng Retune Speed, Humanize
    }

    void setRetuneSpeed(float ms) { retuneSpeed = ms; }
    void setKey(int root, int scaleType) { currentRoot = root; currentScale = scaleType; }

private:
    double sampleRate;
    float retuneSpeed = 20.0f;
    int currentRoot = 0; // C
    int currentScale = 0; // Major
};
