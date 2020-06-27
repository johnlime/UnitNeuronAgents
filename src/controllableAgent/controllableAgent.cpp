//
//  controllableAgent.cpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/06/26.
//

#include "controllableAgent.hpp"

ControllableAgent :: ControllableAgent(ofVec2f _init_position, ofVec3f _color)
{
    position = _init_position;
    color = _color;
}

void ControllableAgent :: ca_display()
{
    ofSetColor(color.x, color.y, color.z);
    ofDrawCircle(position.x, position.y, radius);
}
