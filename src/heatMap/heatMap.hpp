//
//  heatCell.hpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/07/04.
//

#ifndef heatCell_hpp
#define heatCell_hpp

#include <stdio.h>
#include <stdlib.h>
#include <ofMain.h>

struct HeatCell
{
    int x_index;
    int y_index;
    bool selected;
};

class HeatMap
{
private:
    HeatCell* all_heat_cells;
    int width;
    int height;
    int pixel_width;
    int pixel_height;
    int num_selected_cells;
    
public:
    HeatMap(int _width, int _height, int _pixels);
    HeatMap(int _width, int _height, int _pixel_width, int _pixel_height);
    ~HeatMap();
    void select(int _x, int _y);
    void select_by_pixel(int _pixel_x, int _pixel_y);
    int display_num_selected_cells();
    void display();
    void sample(int* result);
};

#endif /* heatCell_hpp */
