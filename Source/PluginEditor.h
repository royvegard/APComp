#pragma once

#include "PluginProcessor.h"


class KnobLook1 : public juce::LookAndFeel_V4 {
    
public:
    
    KnobLook1();
    ~KnobLook1() override = default;
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override;

    
private:
    
    juce::Image knobImage;
};


class GUI  : public juce::AudioProcessorEditor, public juce::Slider::Listener, private juce::Timer {
    
public:
    
    GUI (APComp&);
    ~GUI() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;
    void mouseDown (const juce::MouseEvent& event) override;
    void sliderValueChanged(juce::Slider* slider) override;
        
private:
    
    APComp& audioProcessor;
        
    KnobLook1 knobLook1;
    
    juce::Image backgroundImage;
    
    juce::Font customTypeface;
        
    juce::Slider inGainSlider;
    juce::Slider outGainSlider;
    juce::Slider convexitySlider;
    juce::Slider attackSlider;
    juce::Slider releaseSlider;
    juce::Slider thresholdSlider;
    juce::Slider ratioSlider;
    juce::Slider channelLinkSlider;
    juce::Slider sidechainSlider;
    juce::Slider variMuSlider;
    juce::Slider foldSlider;
    juce::Slider feedbackSlider;
    juce::Slider inertiaSlider;
    juce::Slider inertiaDecaySlider;
    juce::Slider overdriveSlider;
    juce::Slider oversamplingSlider;
            
    std::vector<std::pair<std::string, std::reference_wrapper<juce::Slider>>> sliders {
        {"inGainSlider",        std::ref(inGainSlider)},
        {"outGainSlider",       std::ref(outGainSlider)},
        {"convexitySlider",     std::ref(convexitySlider)},
        {"attackSlider",        std::ref(attackSlider)},
        {"releaseSlider",       std::ref(releaseSlider)},
        {"thresholdSlider",     std::ref(thresholdSlider)},
        {"ratioSlider",         std::ref(ratioSlider)},
        {"channelLinkSlider",   std::ref(channelLinkSlider)},
        {"sidechainSlider",     std::ref(sidechainSlider)},
        {"variMuSlider",        std::ref(variMuSlider)},
        {"foldSlider",          std::ref(foldSlider)},
        {"feedbackSlider",      std::ref(feedbackSlider)},
        {"inertiaSlider",       std::ref(inertiaSlider)},
        {"inertiaDecaySlider",  std::ref(inertiaDecaySlider)},
        {"overdriveSlider",     std::ref(overdriveSlider)},
        {"oversamplingSlider",  std::ref(oversamplingSlider)}
    };

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> inGainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> outGainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> convexityAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> thresholdAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> ratioAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> channelLinkAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sidechainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> variMuAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> foldAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> inertiaAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> inertiaDecayAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> overdriveAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> oversamplingAttachment;
        
    bool metersActive;
    TextScreen textScreen;

    const float metersLeft    = 619.3f;
    const float metersRight   = 662.0f;
    const float metersTop     = 23.0f;
    const float metersBottom  = 261.0f;
    
    const int knobRow1 = 244;
    const int knobRow2 = 327;
    const int knobRow3 = 411;
    
    const int knobColumn1 = 74;
    const int knobColumn2 = 221;
    const int knobColumn3 = 370;
    const int knobColumn4 = 519;
    
    const int presetRow1 = 0;
    const int presetRow2 = 0;
    
    const int presetColumn1 = 0;
    const int presetColumn2 = 0;
    const int presetColumn3 = 0;
    const int presetColumn4 = 0;
    const int presetColumn5 = 0;
    
    const int textScreenL = 168;
    const int textScreenR = 418;
    const int textScreenT = 382;
    const int textScreenB = 492;
    
    void toggleMeters();
    void toggleVariMu();
    void switchOversampling(bool active);
    void switchSidechain(bool active);
    void paintMeters(juce::Graphics &g);
    void paintButtons(juce::Graphics &g);
    void paintBackground(juce::Graphics &g);
    void paintTextScreen(juce::Graphics &g, std::string &textScreenString);
    std::string updateTextScreen();
    ButtonName determineButton(const juce::MouseEvent &event);
    
    std::mutex textScreenMutex;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI)
};
