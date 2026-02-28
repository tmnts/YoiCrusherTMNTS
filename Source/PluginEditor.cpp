#include "PluginProcessor.h"
#include "PluginEditor.h"

void YoiCrusherTMNTSAudioProcessorEditor::paint (juce::Graphics& g)
{
    // VS Code Dark Background
    g.fillAll (juce::Colour (0xff1e1e1e)); 

    // Берем LFO из процессора и делаем из него прозрачность (Alpha)
    float lfo = audioProcessor.lastLfoValue;
    float alpha = 0.4f + (lfo + 1.0f) * 0.3f; // Пульсация от 0.4 до 1.0

    // Розовый неон
    juce::Colour neonPink = juce::Colour (0xffff69b4).withAlpha (alpha);
    g.setColour (neonPink);
    
    g.setFont (juce::Font ("Consolas", 16.0f, juce::Font::bold));
    g.drawText ("> YOINESS_ACTIVE", 25, 25, 300, 20, juce::Justification::left);
    g.drawText ("> STATUS: CRUSHING_BY_BPM", 25, 45, 300, 20, juce::Justification::left);

    // Пульсирующая рамка
    g.drawRect (getLocalBounds().reduced (15), (int)(alpha * 4.0f));
}