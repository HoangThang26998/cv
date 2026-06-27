#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include <vector>

struct PitchPoint
{
    double time;
    float frequency;
};

class GraphModeEditor : public juce::Component
{
public:
    GraphModeEditor() {}

    void paint(juce::Graphics& g) override
    {
        // Vẽ lưới cao độ (Pitch Grid)
        // Vẽ đường cao độ gốc (Red line)
        // Vẽ đường cao độ đã chỉnh sửa (Blue line)
    }

    void mouseDown(const juce::MouseEvent& e) override
    {
        // Cho phép người dùng vẽ đường cao độ mục tiêu
    }

private:
    std::vector<PitchPoint> originalPitchData;
    std::vector<PitchPoint> editedPitchData;
};
