cmake_minimum_required(VERSION 3.15)

project(AutoTune11 VERSION 1.0.0 LANGUAGES CXX)

set(JUCE_PATH /home/ubuntu/JUCE CACHE PATH "Path to JUCE")
add_subdirectory(${JUCE_PATH} _juce)

juce_add_plugin(AutoTune11
    COMPANY_NAME "HT Audio 98"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE Manu
    PLUGIN_CODE Atun
    FORMATS VST3 AU
    PRODUCT_NAME "AutoTune11")

target_sources(AutoTune11 PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h)

target_compile_definitions(AutoTune11 PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0)

target_link_libraries(AutoTune11 PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_gui_extra
    juce::juce_dsp)
