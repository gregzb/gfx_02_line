#pragma once

#include <string>
#include <limits>
#include "Utils.hpp"
#include "PixelGrid.hpp"

class Screen : public PixelGrid<Color>
{
public:
    Screen(int width, int height);

    void toFile(std::string fileName);
};