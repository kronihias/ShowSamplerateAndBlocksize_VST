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
class ShowSamplerateAndBlocksizeAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                                        public juce::Timer
{
public:
    ShowSamplerateAndBlocksizeAudioProcessorEditor (ShowSamplerateAndBlocksizeAudioProcessor&);
    ~ShowSamplerateAndBlocksizeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void timerCallback() override;
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ShowSamplerateAndBlocksizeAudioProcessor& audioProcessor;

    juce::Label lbl_fs;
    juce::Label lbl_blocksize;
    
    juce::TextEditor txt_logfile;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ShowSamplerateAndBlocksizeAudioProcessorEditor)
};
