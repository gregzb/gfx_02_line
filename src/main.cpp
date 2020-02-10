#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <limits>

#include "Utils.hpp"
#include "PixelGrid.hpp"
#include "Screen.hpp"

int main()
{
    Screen screen(500, 500);

    double centerX = screen.getWidth() / 2;
    double centerY = screen.getHeight() / 2;

    double maxDist = std::sqrt(std::pow(250, 2) + std::pow(250, 2)) * 1.1;

    for (int row = 0; row < screen.getHeight(); row++)
    {
        for (int col = 0; col < screen.getHeight(); col++)
        {
            screen(row, col) = {
                static_cast<int>(37 - std::sqrt(std::pow(row + 43.3 - centerY, 2) + std::pow(col - 50 - centerX, 2)) / maxDist * 255) % 256,
                static_cast<int>(37 - std::sqrt(std::pow(row + 43.3 - centerY, 2) + std::pow(col + 50 - centerX, 2)) / maxDist * 255) % 256,
                static_cast<int>(37 - std::sqrt(std::pow(row - 43.3 - centerY, 2) + std::pow(col - centerX, 2)) / maxDist * 255) % 256,
                255};
        }
    }

    screen.toFile("img.ppm");

    return 0;
}