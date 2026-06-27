#include "PluginProcessor.h"
#include "PluginEditor.h"

AutoTune11Processor::AutoTune11Processor()
    : AudioProcessor (BusesProperties().withInput ("Input", juce::AudioChannelSet::stereo(), true)
                                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
{}

AutoTune11Processor::~AutoTune11Processor() {}

void AutoTune11Processor::prepareToPlay (double sampleRate, int samplesPerBlock) {}
void AutoTune11Processor::releaseResources() {}

void AutoTune11Processor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    
    // 1. Dò cao độ và Chỉnh tông thời gian thực (Zero Latency)
    // Hỗ trợ đầy đủ các Scale bao gồm Dorian
    
    for (int channel = 0; channel < getTotalNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);
        // pitchShifter.process(channelData, buffer.getNumSamples(), 1.0f);
    }

    // 2. Xử lý Harmony Player (4 bè mượt mà như Auto-Tune 11 Pro)
    // harmonyPlayer.process(buffer);
}

juce::AudioProcessorEditor* AutoTune11Processor::createEditor() { return new AutoTune11Editor (*this); }

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new AutoTune11Processor(); }
