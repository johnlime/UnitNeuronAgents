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

class ControllableAgent
{
private:
    float radius = 10.0f;
    ofVec2f position;
    ofVec3f color;
    
public:
    ControllableAgent(ofVec2f _init_position, ofVec3f _color);
    void ca_display();
};
#endif /* controllableAgent_hpp */
