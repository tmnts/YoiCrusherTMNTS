#pragma once
#include "PluginProcessor.h"

class YoiCrusherTMNTSAudioProcessorEditor : public juce::AudioProcessorEditor, public juce::Timer
{
public:
    YoiCrusherTMNTSAudioProcessorEditor (YoiCrusherTMNTSAudioProcessor& p) : AudioProcessorEditor (&p), audioProcessor (p) 
    {
        setSize (400, 300); // Размер окна плагина в Ableton
        startTimerHz(60); // 60 кадров в секунду
    }

    void paint (juce::Graphics&) override;
    void timerCallback() override { repaint(); }
    void resized() override {}

private:
    YoiCrusherTMNTSAudioProcessor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YoiCrusherTMNTSAudioProcessorEditor)
};