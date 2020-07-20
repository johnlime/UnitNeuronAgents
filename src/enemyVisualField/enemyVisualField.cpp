//
//  enemyVisualField.cpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/07/07.
//

#include "enemyVisualField.hpp"
#define EPSILON 0.7
#define VISUAL_RANGE 100
#define DELTA 0.3

EnemyVisualField :: EnemyVisualField(int _pixel_width, int _pixel_height)
{
    pixel_width = _pixel_width;
    pixel_height = _pixel_height;
    ratio = (float)pixel_height / (float)pixel_width;
}

void EnemyVisualField :: add_collider(Collider _new_collider)
{
    collider_list.push_back(_new_collider);
}

void EnemyVisualField :: add_collider(std::string const &_collider_type)
{
//    if (_collider_type = "")
//    {
//
//    }
//    collider_list.push_back();
}

void EnemyVisualField :: setEnemyPosition(float _enemy_pos_x, float _enemy_pos_y)
{
    enemy_position.x = _enemy_pos_x;
    enemy_position.y = _enemy_pos_y;
}

void EnemyVisualField :: hidden_los_sample()
{
    float tmp;
    ofVec2f tmp_vec;
    bool random;
    
    // explore surrounding of known
    if (rand() / RAND_MAX < EPSILON && hidden_samples.size() > 0)
    {
        random = false;
        // select an index from hidden_samples -1
        int selected = rand() % (hidden_samples.size());
        
        // search the surrounding
        tmp = hidden_samples[selected].angular_ratio + DELTA * (float) rand() / RAND_MAX;
    }
    
    // random exploration
    else
    {
        random = true;
        tmp = (float) rand() / RAND_MAX; // sample an anglular ratio
    }
    
    for (int coef = 0; coef < VISUAL_RANGE; coef++)
    {
        tmp_vec.x = enemy_position.x + coef * cos(2 * M_PI * tmp);
        tmp_vec.y = enemy_position.y + coef * sin(2 * M_PI * tmp);
        
        for (int i = 0; i < collider_list.size(); i++)
        {
            if (collider_list[i].collision_detect(tmp_vec)) // coef hits object
            {
                HiddenLOS tmp_los;
                tmp_los.angular_ratio = tmp;
                tmp_los.param = coef;
                
                // add to hidden samples
                hidden_samples.push_back(tmp_los);
                
                break;
            }
        }
    }
}

ofVec2f EnemyVisualField :: sample()
{
    if (ratio != (float)pixel_height / (float)pixel_width)
    {
        throw "The ratio of the dimensions does not match the ratio of the VisualField instance!";
    }
    
    int sample_index = rand() % hidden_samples.size();
    float sample_coef = (RAND_MAX - hidden_samples[sample_index].param) * ((float) rand() / RAND_MAX)
                        + hidden_samples[sample_index].param;
    
    ofVec2f result;
    result.x = enemy_position.x + sample_coef * cos(2 * M_PI * hidden_samples[sample_index].angular_ratio);
    result.y = enemy_position.y + sample_coef * sin(2 * M_PI * hidden_samples[sample_index].angular_ratio);
    return result;
}

void EnemyVisualField :: display()
{
    // display colliders as wireframe
}
