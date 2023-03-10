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
class OfficialJucePluginTutorial1AudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener
{
public:
    OfficialJucePluginTutorial1AudioProcessorEditor (OfficialJucePluginTutorial1AudioProcessor&);
    ~OfficialJucePluginTutorial1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OfficialJucePluginTutorial1AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OfficialJucePluginTutorial1AudioProcessorEditor)
    juce::Slider midiVelocitySlider;
    void sliderValueChanged(juce::Slider* slider) override;
};
