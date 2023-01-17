/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor::AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor (AP_juce_framework_tutorial_64_audio_pluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 300);
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setRange(0.0f, 1.0f, 0.01f);
    
}

AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor::~AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor()
{
}

//==============================================================================
void AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
