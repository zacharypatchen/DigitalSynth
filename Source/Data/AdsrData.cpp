/*
  ==============================================================================

    AdsrData.cpp
    Created: 2 Mar 2023 4:11:32pm
    Author:  Zachary Patchen

  ==============================================================================
*/

#include "AdsrData.h"
#include <JuceHeader.h>

void AdsrData::updateADSR(const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;
    setParameters(adsrParams);
}
