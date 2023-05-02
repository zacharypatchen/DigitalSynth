/*
  ==============================================================================

    OscData.h
    Created: 2 Mar 2023 4:59:09pm
    Author:  Zachary Patchen

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
class OscData : public juce::dsp::Oscillator<float>
{
public:
    void setWaveType(const int choice);
    void prepareToPlay(juce::dsp::ProcessSpec& spec);
    void setWaveFrequency(const int midiNoteNumber);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);
    void setFmParams(const float depth, const float freq);
private:
    juce::dsp::Oscillator<float>fmOsc{[](float x){return std::sin(x);}};
    float fmMod{0.f};
    float fmDepth{0.f};
    int lastMidiNote=0;
};
