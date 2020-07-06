//
//  visualField.cpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/07/07.
//

#include "visualField.hpp"

VisualField :: VisualField(int _pixel_width, int _pixel_height)
{
    pixel_width = _pixel_width;
    pixel_height = _pixel_height;
    ratio = (float)pixel_height / (float)pixel_width;
}

ofVec2f VisualField :: sample()
{
    if (ratio != (float)pixel_height / (float)pixel_width)
    {
        throw "The ratio of the dimensions does not match the ratio of the VisualField instance!";
    }
    
    ofVec2f result;
    result.x = pixel_width * (float) rand() / RAND_MAX;
    result.y = pixel_height * (float) rand() / RAND_MAX;
    return result;
}
