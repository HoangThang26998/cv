cmake_minimum_required(VERSION 3.15)

project(AutoKey VERSION 1.0.0 LANGUAGES CXX)

set(JUCE_PATH /home/ubuntu/JUCE CACHE PATH "Path to JUCE")
add_subdirectory(${JUCE_PATH} _juce)

juce_add_plugin(AutoKey
    COMPANY_NAME "HT Audio 98"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT TRUE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE Manu
    PLUGIN_CODE Akey
    FORMATS VST3 AU
    PRODUCT_NAME "AutoKey")

target_sources(AutoKey PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h)

target_compile_definitions(AutoKey PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0)

target_link_libraries(AutoKey PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_gui_extra
    juce::juce_dsp)
