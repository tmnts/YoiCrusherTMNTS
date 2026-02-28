#pragma once
#include "PluginProcessor.h"

class YoiCrusherTMNTSAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    YoiCrusherTMNTSAudioProcessorEditor (YoiCrusherTMNTSAudioProcessor& p) : AudioProcessorEditor (&p), audioProcessor (p) 
    {
        setSize (400, 300); // Размер окна плагина в Ableton
    }

    void paint (juce::Graphics&) override;
    void resized() override {}

private:
    YoiCrusherTMNTSAudioProcessor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YoiCrusherTMNTSAudioProcessorEditor)
};