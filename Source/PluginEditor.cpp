#include "PluginProcessor.h"
#include "PluginEditor.h"

void YoiCrusherTMNTSAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour (0xff1e1e1e)); // VS Code Background
    g.setColour (juce::Colours::cyan);
    g.setFont (juce::Font ("Consolas", 14.0f, juce::Font::plain));

    g.drawText ("> YOI_CRUSHER_TMNTS_LOADED", 20, 20, 300, 20, juce::Justification::left);
    g.drawText ("> STATUS: READY_TO_CRUSH", 20, 40, 300, 20, juce::Justification::left);
    
    // Рисуем неоновый круг
    auto area = getLocalBounds().reduced (60).toFloat();
    g.drawEllipse (area, 2.0f);
}