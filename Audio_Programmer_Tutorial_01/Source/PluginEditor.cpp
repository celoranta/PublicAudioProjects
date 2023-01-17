/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Audio_Programmer_Tutorial_01AudioProcessorEditor::Audio_Programmer_Tutorial_01AudioProcessorEditor (Audio_Programmer_Tutorial_01AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);
    midiVolume.setSliderStyle(juce::Slider::LinearBarVertical);
    midiVolume.setRange(0.0f, 127.0f, 1.0f);
    midiVolume.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled(true, false, this);
    midiVolume.setTextValueSuffix(" Volume");
    midiVolume.setValue(1.0f);
    addAndMakeVisible(&midiVolume);
    midiVolume.addListener(this);

    
}


Audio_Programmer_Tutorial_01AudioProcessorEditor::~Audio_Programmer_Tutorial_01AudioProcessorEditor()
{
}

//==============================================================================
void Audio_Programmer_Tutorial_01AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::white);
    g.setColour(juce::Colours::black);
    g.setFont(15.0f);
    g.drawFittedText("MIDI Volume", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}
    

void Audio_Programmer_Tutorial_01AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}


void Audio_Programmer_Tutorial_01AudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    audioProcessor.noteOnVel = midiVolume.getValue();
}
