#pragma once
#include <juce_core/juce_core.h>
#include <vector>

enum class ScaleType
{
    Major,
    Minor,
    Dorian,
    Phrygian,
    Lydian,
    Mixolydian,
    Locrian,
    Chromatic
};

class ScaleSystem
{
public:
    static std::vector<int> getScaleIntervals(ScaleType type)
    {
        switch (type)
        {
            case ScaleType::Major:      return { 0, 2, 4, 5, 7, 9, 11 };
            case ScaleType::Minor:      return { 0, 2, 3, 5, 7, 8, 10 };
            case ScaleType::Dorian:     return { 0, 2, 3, 5, 7, 9, 10 }; // Dorian: 1 2 b3 4 5 6 b7
            case ScaleType::Mixolydian: return { 0, 2, 4, 5, 7, 9, 10 };
            case ScaleType::Chromatic:  return { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
            default:                    return { 0, 2, 4, 5, 7, 9, 11 };
        }
    }

    static int snapToScale(int midiNote, int rootNote, ScaleType type)
    {
        auto intervals = getScaleIntervals(type);
        int noteInOctave = (midiNote - rootNote) % 12;
        if (noteInOctave < 0) noteInOctave += 12;

        int bestNote = intervals[0];
        int minDiff = 12;

        for (int interval : intervals)
        {
            int diff = std::abs(noteInOctave - interval);
            if (diff < minDiff)
            {
                minDiff = diff;
                bestNote = interval;
            }
        }

        return (midiNote / 12) * 12 + rootNote + bestNote;
    }
};
