#include <algorithm>
#include <cmath>
#include <limits>
#include <unordered_map>

#include "APCommon.h"


double linearToExponential(double linearValue, double minValue, double maxValue)
{
    linearValue = std::clamp(linearValue, minValue, maxValue);
    double normalized = (linearValue - minValue) / (maxValue - minValue);
    double exponentialValue = std::pow(normalized, 2.0);
    double result = minValue + exponentialValue * (maxValue - minValue);
    return result;
}

double gainToDecibels(double gain) {
    if (gain <= 0.0)
        return -1000;
    
    if (gain > 1000) gain = 1000;

    return 20.0 * std::log10(gain);
}

double decibelsToGain(double decibels) {
    if (decibels <= -1000)
        return 0.0;
    
    if (decibels > 1000) decibels = 1000;
    
    return std::pow(10.0, decibels / 20.0);
}


std::string floatToStringWithTwoDecimalPlaces(float value) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    return stream.str();
}


std::string getParameterNameFromEnum(ParameterNames index) {
    switch (index) {
        case ParameterNames::inGain:        return "inGain";
        case ParameterNames::outGain:       return "outGain";
        case ParameterNames::convexity:     return "convexity";
        case ParameterNames::attack:        return "attack";
        case ParameterNames::release:       return "release";
        case ParameterNames::threshold:     return "threshold";
        case ParameterNames::ratio:         return "ratio";
        case ParameterNames::channelLink:   return "channelLink";
        case ParameterNames::feedback:      return "feedback";
        case ParameterNames::inertia:       return "inertia";
        case ParameterNames::inertiaDecay:  return "inertiaDecay";
        case ParameterNames::ceiling:       return "ceiling";
        case ParameterNames::sidechain:     return "sidechain";
        case ParameterNames::metersOn:      return "metersOn";
        case ParameterNames::oversampling:  return "oversampling";
        case ParameterNames::fold:          return "fold";
        case ParameterNames::variMu:        return "variMu";
        default: throw std::out_of_range("Invalid index for getParameterNameFromEnum");
    }
}


ParameterNames getParameterEnumFromParameterName(const std::string& name) {
    static const std::unordered_map<std::string, ParameterNames> nameToEnumMap = {
        {"inGain",        ParameterNames::inGain},
        {"outGain",       ParameterNames::outGain},
        {"convexity",     ParameterNames::convexity},
        {"attack",        ParameterNames::attack},
        {"release",       ParameterNames::release},
        {"threshold",     ParameterNames::threshold},
        {"ratio",         ParameterNames::ratio},
        {"channelLink",   ParameterNames::channelLink},
        {"feedback",      ParameterNames::feedback},
        {"inertia",       ParameterNames::inertia},
        {"inertiaDecay",  ParameterNames::inertiaDecay},
        {"ceiling",       ParameterNames::ceiling},
        {"sidechain",     ParameterNames::sidechain},
        {"metersOn",      ParameterNames::metersOn},
        {"oversampling",  ParameterNames::oversampling},
        {"variMu",        ParameterNames::variMu},
        {"fold",          ParameterNames::fold}
    };

    auto it = nameToEnumMap.find(name);
    if (it != nameToEnumMap.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Invalid parameter name for getEnumFromParameterName");
    }
}
