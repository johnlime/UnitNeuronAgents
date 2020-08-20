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

void ControllableAgent :: update_target(ofVec2f _position)
{
    target_position = _position;
}

void ControllableAgent :: move()
{
    // stop completely if agent is on target position
    if ((position - target_position).length() < 2)
    {
        return;
    }
    
    ofVec2f normalized_direction = (target_position - position).normalize();
    
    // obtain target orientation ratio in radian
    float target_orientation = acos(normalized_direction.x) / M_PI;;
    if ((asin(normalized_direction.y) < 0) - (asin(normalized_direction.y) > 0)) // obtain sign of angle
    {
        target_orientation *= -1;
    }
    
    // translate body if the direction the agent is facing and the target orientation is the same
    if (orientation == target_orientation)
    {
        position += normalized_direction;
    }
    
    // snap to orientation if close
    else if (abs(orientation - target_orientation) <= 0.01)
    {
        orientation = target_orientation;
    }

    // rotate body if otherwise
    else
    {
        if ((target_orientation - orientation) >= 0)
        {
            orientation += 0.01;
        }
        else
        {
            orientation -= 0.01;
        }
    }
}

void ControllableAgent :: display()
{
    ofSetColor(color.x, color.y, color.z);
    ofSetLineWidth(2.0f);
    float sqrt_3_div_2 = sqrt(3) / 2;
    
    // Save global coordinates
    ofPushMatrix();
    
    // Translate position and orientation of local coordinates to the agent
    ofTranslate(position.x, position.y);
    ofRotateDeg(orientation * 360, 0, 0, 1);
    
    // Agent shape
    ofDrawLine(0.0f, radius, sqrt_3_div_2 * radius, - radius / 2);
    ofDrawLine(sqrt_3_div_2 * radius, - radius / 2, 0.0f, 0.0f);
    ofDrawLine(0.0f, 0.0f, - sqrt_3_div_2 * radius, - radius / 2);
    ofDrawLine(- sqrt_3_div_2 * radius, - radius / 2, 0.0f, radius);
    
    // Restore global coordinates
    ofPopMatrix();
}
