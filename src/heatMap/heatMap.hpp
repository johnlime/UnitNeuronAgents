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
    bool selected = false;
};

class HeatMap
{
private:
    HeatCell* all_heat_cells;
    int width;
    int height;
    
public:
    HeatMap(int _width, int _height);
    void select(int _x, int _y);
};

#endif /* heatCell_hpp */
