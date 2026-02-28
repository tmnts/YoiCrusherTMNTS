#include "PluginProcessor.h"
#include "PluginEditor.h"

void YoiCrusherTMNTSAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    // 1. Получаем BPM из Ableton
    auto bpm = 120.0;
    if (auto* ph = getPlayHead()) {
        if (auto pos = ph->getPosition())
            bpm = pos->getBpm().hasValue() ? *(pos->getBpm()) : 120.0;
    }

    // 2. Настраиваем скорость пульсации (Yoiness)
    float yoiness = 2.0f; 
    float lfoHz = ((float)bpm / 60.0f) * yoiness;
    float phaseIncrement = lfoHz / (float)getSampleRate();

    for (int i = 0; i < buffer.getNumSamples(); ++i)
    {
        // 3. Генерируем LFO
        float lfoSin = std::sin(lfoPhase * 2.0f * 3.14159f);
        lastLfoValue = lfoSin; // Отправляем в интерфейс
        lfoPhase = std::fmod(lfoPhase + phaseIncrement, 1.0f);

        float left = buffer.getSample(0, i);
        float right = buffer.getSample(1, i);

        float mid = (left + right) * 0.5f;
        float side = (left - right) * 0.5f;

        // --- УМНЫЙ БИТКРАШ (от 4 до 16 бит в ритме LFO) ---
        float currentBits = 10.0f + (lfoSin * 6.0f); 
        float levels = (float)std::pow(2.0, (double)currentBits);
        mid = std::round(mid * levels) / levels;

        // --- ЗАЩИТА ОТ КЛИППА (Soft Saturation) ---
        mid = std::tanh(mid * 1.4f); 
        side *= 1.1f; 

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