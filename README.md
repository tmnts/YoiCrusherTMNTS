# YoiCrusherTMNTS v2.2 🧪💖

**Signature Sound for Lera Edition**  
Native VST3 bitcrusher with Mid-Side processing and BPM synchronization.

### 🚀 Features:
- **Mid-Side Bitcrushing:** Destroys the Mid channel while keeping Stereo side clean for mono-compatibility.
- **BPM-Synced LFO:** Dynamic `Yoiness` modulation synced with DAW PlayHead.
- **Soft-Saturator:** Internal `std::tanh` clipping to prevent digital peaks (anti-clipping).
- **Dark Terminal UI:** Pulse-animated Neon Pink interface synced with LFO phase.

### 🛠 Tech Stack:
- **C++ 20** / JUCE Framework
- **CMake** build system
- Manual memory management and DSP optimization

### 🛠 How to Build:
1. Clone with submodules: `git clone --recursive [URL]`
2. Run: `cmake -B build -G "Visual Studio 17 2022" -A x64`
3. Build: `cmake --build build --config Release`