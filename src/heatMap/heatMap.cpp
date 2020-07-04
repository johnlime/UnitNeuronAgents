//
//  heatCell.cpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/07/04.
//

#include "heatMap.hpp"

HeatMap :: HeatMap(int _width, int _height)
{
    width = _width;
    height = _height;
    all_heat_cells = (HeatCell*) malloc(sizeof(HeatCell) * (width * height)); // array by rows
}

void HeatMap :: select(int _x, int _y)
{
    all_heat_cells[_x + _y * width].selected = !all_heat_cells[_x + _y * width].selected;
}
