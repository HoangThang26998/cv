#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

class AutoTune11Processor : public juce::AudioProcessor
{
public:
    AutoTune11Processor();
    ~AutoTune11Processor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return "AutoTune11"; }
    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram (int index) override {}
    const juce::String getProgramName (int index) override { return {}; }
    void changeProgramName (int index, const juce::String& newName) override {}

    void getStateInformation (juce::MemoryBlock& destData) override {}
    void setStateInformation (const void* data, int sizeInBytes) override {}

public:
    void setRetuneSpeed(float speed) { retuneSpeed = speed; }
    void setHumanize(float amount) { humanize = amount; }
    void setFlexTune(float amount) { flexTune = amount; }
    
private:
    // Core DSP Modules
    HarmonyPlayer harmonyPlayer;
    float retuneSpeed = 20.0f;
    float humanize = 0.0f;
    float flexTune = 0.0f;
    bool classicMode = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoTune11Processor)
};
