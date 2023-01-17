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
    sliderWidth = 100;
    sliderHeight = 150;
    setSize (200 , 300);
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setRange(-60.0f, 0.0f, 0.01f);
    mGainSlider.setValue(0.0f);
    addAndMakeVisible(mGainSlider);
    mGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.addListener(this);
}

AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor::~AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor()
{
}

//==============================================================================
void AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mGainSlider.setBounds(getWidth()/2 - sliderWidth / 2, getHeight()/2 - sliderHeight / 2, sliderWidth, sliderHeight);
}

void AP_juce_framework_tutorial_64_audio_pluginAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &mGainSlider) {
        audioProcessor.mGain = mGainSlider.getValue();
    }
}
