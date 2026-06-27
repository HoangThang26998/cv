#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "KeyDetector.h"

class AutoKeyProcessorInternal : public AutoKeyProcessor
{
public:
    KeyDetector keyDetector;
    
    void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override
    {
        juce::ScopedNoDenormals noDenormals;
        
        // 1. Dò tông tự động liên tục
        keyDetector.processBlock(buffer, getSampleRate());
        
        // 2. Tự động gửi Key sang Auto-Tune (Auto-Send)
        if (autoSendEnabled && keyDetector.hasNewKey()) {
            sendKeyToAutoTune(keyDetector.getDetectedKey(), keyDetector.getDetectedScale());
        }

        // 3. Xử lý Smart Key Lift (Tự lên tông cuối bài)
        auto playHead = getPlayHead();
        if (playHead != nullptr) {
            auto position = playHead->getPosition();
            if (position.hasValue()) {
                smartKeyLift.update(position->getTimeInSeconds().orFallback(0.0), 
                                   position->getDurationInSeconds().orFallback(300.0));
            }
        }
    }

    void sendKeyToAutoTune(juce::String key, juce::String scale) {
        // Gửi MIDI SysEx hoặc CC để các plugin Auto-Tune nhận được
    }

private:
    bool autoSendEnabled = true;
    SmartKeyLift smartKeyLift;
};

// Lưu ý: Cần refactor lại PluginProcessor.h để chứa keyDetector hoặc dùng Pimpl
