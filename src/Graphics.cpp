#include "Graphics.hpp"
#include "Screen.hpp"
#include "Vec.hpp"
#include "Utils.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <limits>
#include <tuple>

Graphics::Graphics(Screen &screen) : screen(screen){};

void Graphics::drawLine(double x0, double y0, double z0, double x1, double y1, double z1, Color color, bool debug) const
{
    std::vector<Vec> pixels = Utils::linePixels(x0, y0, x1, y1);

    for (auto pixel : pixels)
    {
        screen(pixel[1], pixel[0]) = color;
    }
}

void Graphics::drawLine(double x0, double y0, double x1, double y1, Color color, bool debug) const
{
    drawLine(x0, y0, 0, x1, y1, 0, color);
}

void Graphics::clear(Color color) const
{
    for (int row = 0; row < screen.getHeight(); row++)
    {
        for (int col = 0; col < screen.getWidth(); col++)
        {
            screen(row, col) = color;
        }
    }
}
