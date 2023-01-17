/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor (AP_juce_framework_tutorial_64_audio_pluginAudioProcessor&);
    ~AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AP_juce_framework_tutorial_64_audio_pluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor)
    juce::Slider mGainSlider;
    int sliderWidth;
    int sliderHeight;
};
