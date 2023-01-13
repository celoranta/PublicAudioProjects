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
class Audio_Programmer_Tutorial_01AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Audio_Programmer_Tutorial_01AudioProcessorEditor (Audio_Programmer_Tutorial_01AudioProcessor&);
    ~Audio_Programmer_Tutorial_01AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Audio_Programmer_Tutorial_01AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Audio_Programmer_Tutorial_01AudioProcessorEditor)
};
