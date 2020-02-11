#include "Utils.hpp"
#include "Vec.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

Color::Color(){};
Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a){};
Color::Color(int r, int g, int b, int a)
{
    this->r = (unsigned char)r;
    this->g = (unsigned char)g;
    this->b = (unsigned char)b;
    this->a = (unsigned char)a;
}

int Utils::sign(double x)
{
    return (x > 0) - (x < 0);
}

double Utils::inverseLerp(double a, double b, double val)
{
    return (val - a) / (b - a);
}

double Utils::lerp(double a, double b, double t)
{
    return (1 - t) * a + t * b;
}

std::vector<Vec> Utils::linePixels(double x0, double y0, double x1, double y1, bool flipped)
{
    std::vector<Vec> temp;
    if (x1 < x0)
    {
        temp = linePixels(x1, y1, x0, y0, flipped);
        std::reverse(temp.begin(), temp.end());
        return temp;
    }

    long x0r = std::lround(x0), x1r = std::lround(x1), y0r = std::lround(y0), y1r = std::lround(y1);

    long dY = y1r - y0r, dX = x1r - x0r;

    if (std::abs(dY) > dX)
    {
        return linePixels(y0, x0, y1, x1, true);
    }

    int dir = sign(dY);

    dY = std::abs(dY) * 2;
    
    int d = dY-dX;

    dX *= 2;

    int y = y0r;
    for (int x = x0r; x <= x1r; x++)
    {
        if (!flipped)
            temp.push_back({{static_cast<double>(x), static_cast<double>(y)}});
        else
            temp.push_back({{static_cast<double>(y), static_cast<double>(x)}});

        if (d > 0)
        {
            y += dir;
            d -= dX;
        }
        d += dY;
    }
    return temp;
}