//
//  enemyVisualField.cpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/07/07.
//

#include "enemyVisualField.hpp"
#define EPSILON 0.7
#define VISUAL_RANGE 100

EnemyVisualField :: EnemyVisualField(int _pixel_width, int _pixel_height)
{
    pixel_width = _pixel_width;
    pixel_height = _pixel_height;
    ratio = (float)pixel_height / (float)pixel_width;
}

void hidden_los_sample()
{
    if (rand() / RAND_MAX < EPSILON)
    {
        // random exploration
        float tmp = (float) rand() / RAND_MAX; // sample an anglular ratio
        float x, y;
        for (int coef = 0; coef < VISUAL_RANGE; coef++)
        {
            x = coef * cos(2 * M_PI * tmp);
            y = coef * sin(2 * M_PI * tmp);
            
            if (true) // coef hits object
            {
                // add to hidden samples
                break;
            }
        }
    }
    
    else{
        // explore surrounding of known
        
    }
}

ofVec2f EnemyVisualField :: sample()
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
