#include <fstream>
#include "Screen.hpp"
#include "PixelGrid.hpp"

Screen::Screen(int width, int height) : PixelGrid(width, height){
    
}

void Screen::toFile(std::string fileName)
{
    std::ofstream myfile;
    myfile.open(fileName);
    myfile << "P3\n"
           << width << " " << height << "\n255\n";

    for (int row = getHeight() - 1; row >= 0; row--)
    {
        for (int col = 0; col < getWidth(); col++)
        {
            Color color = pixelAt(row, col);
            myfile << " " << +color.r << " " << +color.g << " " << +color.b << "  ";
        }
        myfile << "\n";
    }
    myfile.close();
}