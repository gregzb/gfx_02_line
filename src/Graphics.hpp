#pragma once

#include "Utils.hpp"
#include "Vec.hpp"

class Screen;

class Graphics
{
private:
    Screen &screen;

public:
    Graphics(Screen &screen);
    void drawLine(double x0, double y0, double z0, double x1, double y1, double z1, Color color, bool debug = false) const;
    void drawLine(double x0, double y0, double x1, double y1, Color color, bool debug = false) const;
    void clear(Color color) const;
};