//
//  enemyVisualField.hpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/07/07.
//

#ifndef enemyVisualField_hpp
#define enemyVisualField_hpp

#include <stdio.h>
#include <vector>
#include <ofMain.h>

class EnemyVisualField
{
private:
    float ratio;
    int pixel_width;
    int pixel_height;
    
    ofVec2f enemy_position; // position expressed with 0.0f ~ 1.0f
    vector<ofVec3f> hidden_samples; // {angle; end_point in LOS; parameter where hidden area starts}
    void hidden_los_sample(); // choose a random angle + search surrounding angles for hidden areas
    
public:
    EnemyVisualField(int _pixel_width, int _pixel_height);
    ofVec2f sample(); // sample point from hidden_samples
};

#endif
