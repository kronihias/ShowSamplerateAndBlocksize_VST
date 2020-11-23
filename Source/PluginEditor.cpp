/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ShowSamplerateAndBlocksizeAudioProcessorEditor::ShowSamplerateAndBlocksizeAudioProcessorEditor (ShowSamplerateAndBlocksizeAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible (lbl_fs);
    lbl_fs.setText("no fs set yet", juce::dontSendNotification);
    lbl_fs.setFont (juce::Font (15.00f, juce::Font::plain));
    lbl_fs.setJustificationType (juce::Justification::centredLeft);
    lbl_fs.setEditable (false, false, false);
    
    addAndMakeVisible (lbl_blocksize);
    lbl_blocksize.setText("no blocksize set yet ", juce::dontSendNotification);
    lbl_blocksize.setFont (juce::Font (15.00f, juce::Font::plain));
    lbl_blocksize.setJustificationType (juce::Justification::centredLeft);
    lbl_blocksize.setEditable (false, false, false);
    
    addAndMakeVisible (txt_logfile);
    txt_logfile.setMultiLine (true);
    txt_logfile.setReturnKeyStartsNewLine (false);
    txt_logfile.setReadOnly (true);
    txt_logfile.setScrollbarsShown (true);
    txt_logfile.setCaretVisible (false);
    txt_logfile.setPopupMenuEnabled (true);
    txt_logfile.setText ("logfilename");
    txt_logfile.setFont(juce::Font(10,1));
    
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);
    
    
    startTimer(80);
}

ShowSamplerateAndBlocksizeAudioProcessorEditor::~ShowSamplerateAndBlocksizeAudioProcessorEditor()
{
}

//==============================================================================
void ShowSamplerateAndBlocksizeAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Check Samplerate and Blocksize the host is reporting!", getLocalBounds(), juce::Justification::topLeft, 1);
}

void ShowSamplerateAndBlocksizeAudioProcessorEditor::resized()
{
    lbl_fs.setBounds (10, 30, 150, 20);
    lbl_blocksize.setBounds (10, 60, 150, 20);
    
    txt_logfile.setBounds (10, 120, 340, 50);
}

void ShowSamplerateAndBlocksizeAudioProcessorEditor::timerCallback()
{
    juce::String fs = "fs = ";
    fs << audioProcessor.getSampleRate();
    fs << " [Hz]";

    lbl_fs.setText(fs, juce::dontSendNotification);
    
    
    juce::String blocksize = "blocksize = ";
    blocksize << audioProcessor.getBlockSize();
    blocksize << " [smpls]";

    lbl_blocksize.setText(blocksize, juce::dontSendNotification);
    
    
    txt_logfile.setText(audioProcessor.getLogFilename(), juce::dontSendNotification);
}
