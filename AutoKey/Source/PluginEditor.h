#pragma once
#include "PluginProcessor.h"

class AutoKeyEditor : public juce::AudioProcessorEditor
{
public:
    AutoKeyEditor (AutoKeyProcessor&);
    ~AutoKeyEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AutoKeyProcessor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoKeyEditor)
};
