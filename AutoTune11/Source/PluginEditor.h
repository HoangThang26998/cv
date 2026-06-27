#pragma once
#include "PluginProcessor.h"

class AutoTune11Editor : public juce::AudioProcessorEditor
{
public:
    AutoTune11Editor (AutoTune11Processor&);
    ~AutoTune11Editor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AutoTune11Processor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoTune11Editor)
};
