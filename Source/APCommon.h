#pragma once

#include <map>
#include <string>
#include <JuceHeader.h>

#define PRO_VERSION 0


enum class OversamplingOption {
    None   = 0,
    FIR_1x = 1,
    IIR_1x = 2,
    FIR_2x = 3,
    IIR_2x = 4
};


enum class ButtonName {
    oversamplingON,
    oversamplingOFF,
    sidechainInternal,
    sidechainExternal,
    logo,
    meters,
    variMu,
    none
};


struct TextScreen {
    bool isBool;
    float value;
    bool displayDefaultText;
    int timeout;
    int defaultTimeout;
    std::string parameterName;
    std::string suffix;
    std::string defaultText;
    
    TextScreen()
    : isBool(false),
    value(0.0f),
    displayDefaultText(true),
    timeout(0),
    defaultTimeout(100),
    parameterName(""),
    suffix(""),
#if PRO_VERSION
    defaultText("Versatile Compressor Pro") {}
#else
    defaultText("Versatile Compressor") {}
#endif
};


enum class ParameterNames {
    inGain          = 0,
    outGain         = 1,
    convexity       = 2,
    attack          = 3,
    release         = 4,
    threshold       = 5,
    ratio           = 6,
    channelLink     = 7,
    feedback        = 8,
    inertia         = 9,
    inertiaDecay    = 10,
    sidechain       = 11,
    metersOn        = 12,
    oversampling    = 13,
    overdrive       = 14,
    variMu          = 15,
    fold            = 16,
    END             = 17
};


double linearToExponential(double linearValue, double minValue, double maxValue);
double gainToDecibels(double gain);
double decibelsToGain(double decibels);
std::string floatToStringWithTwoDecimalPlaces(float value);
std::string getParameterNameFromEnum(ParameterNames index);
ParameterNames getParameterEnumFromParameterName(const std::string& name);


class APFont {
public:
    static juce::Font getFont() {
        
        static juce::Font customTypeface = createFont();
        return customTypeface;
    }

private:
    static juce::Font createFont() {
        
        auto typeface = juce::Typeface::createSystemTypefaceFor(
            BinaryData::KnockoutFlyweight_otf, BinaryData::KnockoutFlyweight_otfSize);

        if (typeface != nullptr) {
            
            return juce::Font(juce::FontOptions(typeface));
        }
        
        return juce::Font(juce::FontOptions(14.0f));
    }
};
