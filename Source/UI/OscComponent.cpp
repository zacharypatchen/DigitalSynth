/*
  ==============================================================================

    OscComponent.cpp
    Created: 3 Mar 2023 11:49:39am
    Author:  Zachary Patchen

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId,juce::String fmFreqId, juce::String fmDepthId)
{
    juce::StringArray choices {"Sine", "Saw", "Square"};
    oscWaveSelector.addItemList(choices, 1);
    addAndMakeVisible(oscWaveSelector);
    
    oscWaveSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorId, oscWaveSelector);
    
    waveSelectorLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    waveSelectorLabel.setFont(15.f);
    waveSelectorLabel.setJustificationType(juce::Justification::left);
    addAndMakeVisible(waveSelectorLabel);
    
    setSliderWithLabel(fmFreqSlider, fmFreqLabel, apvts, fmFreqId, fmFreqAttachment);
    setSliderWithLabel(fmDepthSlider, fmDepthLabel, apvts, fmDepthId, fmDepthAttachment);
}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    auto bounds= getLocalBounds().reduced(5);
    auto labelSpace=bounds.removeFromTop(25.F);
    
    g.fillAll(juce::Colours::red);
    g.setColour(juce::Colours::white);
    g.setFont(20.f);
    g.drawText("Oscillator",labelSpace.withX(5),juce::Justification::left);
    g.drawRoundedRectangle(bounds.toFloat(), 5.f, 2.f);
}

void OscComponent::resized()
{
    const auto sliderPosY = 80;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
    
    oscWaveSelector.setBounds(0,0,90,20);
    waveSelectorLabel.setBounds(10, sliderPosY-labelYOffset, 90, labelHeight);
    fmFreqSlider.setBounds(0,sliderPosY,sliderWidth,sliderHeight);
    fmFreqLabel.setBounds(fmFreqSlider.getX(),fmFreqSlider.getY()-labelYOffset, fmFreqSlider.getWidth(),labelHeight);
    
    fmDepthSlider.setBounds(fmFreqSlider.getRight(),sliderPosY,sliderWidth,sliderHeight);
    fmDepthLabel.setBounds(fmDepthSlider.getX(),fmDepthSlider.getY()-labelYOffset,fmDepthSlider.getWidth(),labelHeight);
}

using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
void OscComponent::setSliderWithLabel(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId,std::unique_ptr<Attachment>& attachment)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
    
    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts,paramId, slider);
    
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setFont(15.f);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}
