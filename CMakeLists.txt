cmake_minimum_required(VERSION 3.15)

# Название твоего плагина
project(YoiCrusherTMNTS VERSION 1.0.0 LANGUAGES CXX)

# Подключаем JUCE (укажи правильный путь к папке)
add_subdirectory(JUCE)

# Создаем сам плагин
juce_add_plugin(YoiCrusherTMNTS
    COMPANY_NAME "TMNTS"
    IS_SYNTH FALSE                       # Это эффект (дисторшн/биткрашер)
    NEEDS_MIDI_INPUT FALSE               # Нам не нужно миди
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANT_CONTROL_VILLAGE FALSE    # Без лишнего мусора
    COPY_PLUGIN_AFTER_BUILD TRUE         # Копировать в папку VST3 после билда
    FORMATS VST3 AU                      # Форматы для Ableton
    PRODUCT_NAME "YoiCrusherTMNTS"
)           # Имя, которое увидишь в Ableton

# Какие файлы компилировать (твои исходники)
target_sources(YoiCrusherTMNTS PRIVATE
    "Source/PluginProcessor.cpp"
    "Source/PluginProcessor.h"
    "Source/PluginEditor.cpp"
    "Source/PluginEditor.h"
)
target_compile_definitions(YoiCrusherTMNTS PUBLIC JUCE_VST3_CAN_REPLACE_VST2=0)

# Подключаем модули JUCE (база для звука)
target_link_libraries(YoiCrusherTMNTS PRIVATE
    juce::juce_audio_processors
    juce::juce_audio_basics
    juce::juce_gui_basics
    juce_recommended_config_flags
    juce_recommended_lto_flags)

# Указываем стандарт C++ (для DSP лучше 17-й или 20-й)
target_compile_features(YoiCrusherTMNTS PRIVATE cxx_std_20)