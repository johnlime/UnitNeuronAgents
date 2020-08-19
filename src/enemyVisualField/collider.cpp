//
//  collider.cpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/08/19.
//

#include <stdio.h>
#include "enemyVisualField.hpp"

Collider :: Collider(int x, int y, int _radius)
{
    origin[0] = x;
    origin[1] = y;
    radius = _radius;
}

bool Collider :: collision_detect(ofVec2f input)
{
    if (pow(input.x - origin[0], 2) + pow(input.y - origin[1], 2) < pow(radius, 2))
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

void Collider :: display()
{
    ofDrawCircle(origin[0], origin[1], radius);
}
