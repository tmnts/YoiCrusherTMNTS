#include "PluginProcessor.h"
#include "PluginEditor.h"

void YoiCrusherTMNTSAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (int i = 0; i < buffer.getNumSamples(); ++i)
    {
        // Читаем стерео
        float left = buffer.getSample(0, i);
        float right = buffer.getSample(1, i);

        // Переходим в Mid-Side
        float mid = (left + right) * 0.5f;
        float side = (left - right) * 0.5f;

        // --- БИТКРАШ ТОЛЬКО НА MID (центр) ---
        float drive = 1.5f; // Можно вынести в ручку
        mid = std::tanh(mid * drive); // Софт-клиппинг
        float levels = std::pow(2.0f, 8.0f); // 8-bit
        mid = std::round(mid * levels) / levels;

        // --- SIDE (Стерео) оставляем чистым или чуть расширяем ---
        side *= 1.1f; 

        // Возвращаем в Stereo
        buffer.setSample(0, i, mid + side);
        buffer.setSample(1, i, mid - side);
    }
}
juce::AudioProcessorEditor* YoiCrusherTMNTSAudioProcessor::createEditor()
{
    return new YoiCrusherTMNTSAudioProcessorEditor (*this);
}

// И это для инициализации самого инстанса
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new YoiCrusherTMNTSAudioProcessor();
}
// ... остальные стандартные функции JUCE (оставь пустыми или дефолтными)