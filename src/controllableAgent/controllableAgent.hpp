//
//  controllableAgent.hpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/06/26.
//

#ifndef controllableAgent_hpp
#define controllableAgent_hpp

#include <stdio.h>
#include <ofMain.h>
#include "UnitNeuronsLib.hpp"

class ControllableAgent
{
private:
    float radius = 10.0f;
    ofVec2f position;
    float orientation = 0.5f; // orientation ratio [-1, 1] to 2 * M_PI
    ofVec2f target_position;
    ofVec3f color;
    
public:
    ControllableAgent(ofVec2f _init_position, ofVec3f _color);
    void update_target(ofVec2f _position);
    void move();
    void display();
};
#endif /* controllableAgent_hpp */
