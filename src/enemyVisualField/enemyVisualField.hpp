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
#include <string>

class Collider
{
private:
    int origin [2];
    int radius;
    
public:
    Collider(int x, int y, int _radius);
    bool collision_detect (ofVec2f);
    void display();
};

struct HiddenLOS
{
    float angular_ratio;
    float param;
};

class EnemyVisualField
{
private:
    float ratio; // ratio of the dimensions of the area
    int pixel_width;
    int pixel_height;
    
    ofVec2f enemy_position; // position expressed with 0.0f ~ 1.0f
    vector<Collider> collider_list; // collision detection between enemy visual and meshes
    vector<HiddenLOS> hidden_samples; // {anglular ratio ; parameter where hidden area starts}
    void hidden_los_sample(); // choose a random angle + search surrounding angles for hidden areas
    
public:
    EnemyVisualField(int _pixel_width, int _pixel_height);
    void add_collider(Collider _new_collider); // add collision function with bool output
//    void add_collider(std::string const &_collider_type); // add collision function with bool output
    void setEnemyPosition(float _enemy_pos_x, float _enemy_pos_y);
    ofVec2f sample(); // sample point from hidden_samples
    void display();
};

#endif
