/*
  ==============================================================================

    AdsrData.h
    Created: 2 Mar 2023 4:11:32pm
    Author:  Zachary Patchen

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);
private:
    juce::ADSR::Parameters adsrParams;
};
