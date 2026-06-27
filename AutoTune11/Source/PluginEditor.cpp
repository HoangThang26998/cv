#include "PluginProcessor.h"
#include "PluginEditor.h"

AutoTune11Editor::AutoTune11Editor (AutoTune11Processor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (600, 450);
}

AutoTune11Editor::~AutoTune11Editor() {}

void AutoTune11Editor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::gold);
    g.setFont (20.0f);
    g.drawFittedText ("HT Audio 98 - Auto-Tune Pro 11", getLocalBounds().removeFromTop(50), juce::Justification::centered, 1);
    
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Pitch Correction & Harmony Engine", getLocalBounds(), juce::Justification::centered, 1);
}

void AutoTune11Editor::resized() {}
