//
//  visualField.hpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/07/07.
//

#ifndef visualField_hpp
#define visualField_hpp

#include <stdio.h>
#include <ofMain.h>

class VisualField
{
private:
    float ratio;
    int pixel_width;
    int pixel_height;
    
public:
    VisualField(int _pixel_width, int _pixel_height);
    ofVec2f sample();
};

#endif /* visualField_hpp */
