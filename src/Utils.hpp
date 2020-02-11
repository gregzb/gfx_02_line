#pragma once

#include "Vec.hpp"
#include <vector>

class Color
{
public:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    Color();
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    Color(int r, int g, int b, int a);
};

namespace Utils
{
int sign(double x);
double inverseLerp(double a, double b, double val);
double lerp(double a, double b, double t);
std::vector<Vec> linePixels(double x0, double y0, double x1, double y1, bool flipped = false);
} // namespace Utils