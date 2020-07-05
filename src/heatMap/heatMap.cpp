//
//  heatCell.cpp
//  UnitNeuronAgents
//
//  Created by John Lime on 2020/07/04.
//

#include "heatMap.hpp"

HeatMap :: HeatMap(int _width, int _height, int _pixels)
{
    width = _width;
    height = _height;
    pixel_width = _pixels;
    all_heat_cells = (HeatCell*) malloc(sizeof(HeatCell) * (width * height)); // array by rows
    for (int i = 0; i < width * height; i++)
    {
        all_heat_cells[i].selected = false;
    }
    num_selected_cells = 0;
}

HeatMap :: ~HeatMap()
{
    delete [] all_heat_cells;
}

void HeatMap :: select(int _x, int _y)
{
    all_heat_cells[_x + _y * width].selected = !all_heat_cells[_x + _y * width].selected;
    if (all_heat_cells[_x + _y * width].selected)
    {
        num_selected_cells ++;
    }
    else
    {
        num_selected_cells --;
    }
}

void HeatMap :: select_by_pixel(int _pixel_x, int _pixel_y)
{
    select((int)(_pixel_x / (pixel_width / width)), int(_pixel_y / (pixel_width / width)));
}

int HeatMap :: display_num_selected_cells()
{
    return num_selected_cells;
}

void HeatMap :: display()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (all_heat_cells[j + i * width].selected) ofSetColor(0, 255, 0);
            else ofSetColor(0, 0, 0);
            ofDrawRectangle((pixel_width / width) * j, (pixel_width / width) * i, (pixel_width / width), (pixel_width / width));
        }
    }
}

void HeatMap :: sample(int* result)
{
    if (num_selected_cells == 0)
    {
        throw "No cells are selected!";
    }
    
    int tmp_width = rand() % width;
    int tmp_height = rand() % height;
    
    while (!all_heat_cells[tmp_width + tmp_height * width].selected)
    {
        tmp_width = rand() % width;
        tmp_height = rand() % height;
    }
    
    result[0] = (pixel_width / width) * tmp_width + (int)((pixel_width / width) * ((float)rand() / RAND_MAX));
    result[1] = (pixel_width / width) * tmp_height + (int)((pixel_width / width) * ((float)rand() / RAND_MAX));
}
