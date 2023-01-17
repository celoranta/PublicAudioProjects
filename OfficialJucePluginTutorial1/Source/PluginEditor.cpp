/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OfficialJucePluginTutorial1AudioProcessorEditor::OfficialJucePluginTutorial1AudioProcessorEditor (OfficialJucePluginTutorial1AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);
    midiVelocitySlider.setSliderStyle(juce::Slider::LinearBarVertical);
    midiVelocitySlider.setRange(0.0f, 127.0f, 1.0f);
    midiVelocitySlider.setValue(127.0f);
    midiVelocitySlider.setTextValueSuffix(" Velocity");
    midiVelocitySlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    midiVelocitySlider.setPopupDisplayEnabled(true, false, this);
    
    addAndMakeVisible(&midiVelocitySlider);
    midiVelocitySlider.addListener(this);
}

OfficialJucePluginTutorial1AudioProcessorEditor::~OfficialJucePluginTutorial1AudioProcessorEditor()
{
}

//==============================================================================
void OfficialJucePluginTutorial1AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::white);

    g.setColour (juce::Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("MIDI Velocity", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void OfficialJucePluginTutorial1AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    midiVelocitySlider.setBounds(40, 30, 20, getHeight() -  60);
    
}

void OfficialJucePluginTutorial1AudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    audioProcessor.noteOnVelocity = midiVelocitySlider.getValue();
    
}
