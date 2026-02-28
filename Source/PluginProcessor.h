#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

class YoiCrusherTMNTSAudioProcessor : public juce::AudioProcessor
{
public:
    YoiCrusherTMNTSAudioProcessor() : AudioProcessor (BusesProperties().withInput ("Input", juce::AudioChannelSet::stereo(), true)
                                                                 .withOutput ("Output", juce::AudioChannelSet::stereo(), true)) {}
    ~YoiCrusherTMNTSAudioProcessor() override {}

    void prepareToPlay (double sampleRate, int samplesPerBlock) override {}
    void releaseResources() override {}
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return "YoiCrusherTMNTS"; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram (int index) override {}
    const juce::String getProgramName (int index) override { return {}; }
    void changeProgramName (int index, const juce::String& newName) override {}

    void getStateInformation (juce::MemoryBlock& destData) override {}
    void setStateInformation (const void* data, int sizeInBytes) override {}

private:
    float lfoPhase = 0.0f;     // Текущая фаза LFO
    float lastLfoValue = 0.0f; // Переменная для передачи значения в интерфейс
    
    // Делаем интерфейс другом, чтобы он видел lastLfoValue
    friend class YoiCrusherTMNTSAudioProcessorEditor; 
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YoiCrusherTMNTSAudioProcessor)
};