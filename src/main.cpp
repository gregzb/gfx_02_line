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

    // double wiggle = 7;
    // double wiggleSpeedBase = 0.6;

    // int counter = 0;

    // for (double z2 = 0; z2 < 2 * M_PI; z2 += (2 * M_PI) / 50)
    // {
    //     screen.graphics.clear({0, 0, 0, 255});

    //     double wiggleSpeed = wiggleSpeedBase * std::sin(z2);

    //     int steps = 140;
    //     double r1 = 120;
    //     double r2 = 200;

    //     double offsetAngle = 0.5;

    //     for (int i = 0; i < steps; i++)
    //     {
    //         double angle = i * ((2 * M_PI) / steps);
    //         double x1 = r1 * std::cos(angle + offsetAngle) - wiggle * std::sin(i * wiggleSpeed);
    //         double y1 = r1 * std::sin(angle + offsetAngle) - wiggle * std::sin(i * wiggleSpeed);
    //         double x2 = r2 * std::cos(angle) + wiggle * std::sin(i * wiggleSpeed);
    //         double y2 = r2 * std::sin(angle) + wiggle * std::sin(i * wiggleSpeed);
    //         double x3 = r1 * std::cos(angle - offsetAngle) - wiggle * std::sin(i * wiggleSpeed);
    //         double y3 = r1 * std::sin(angle - offsetAngle) - wiggle * std::sin(i * wiggleSpeed);
    //         screen.graphics.drawLine(screen.getWidth() / 2 + x1, screen.getHeight() / 2 + y1, 0, screen.getWidth() / 2 + x2, screen.getHeight() / 2 + y2, 0, {(i * 6) % 256, 40 + (i * 4) % 216, 120 + (i * 2) % 136, 255});
    //         screen.graphics.drawLine(screen.getWidth() / 2 + x3, screen.getHeight() / 2 + y3, 0, screen.getWidth() / 2 + x2, screen.getHeight() / 2 + y2, 0, {(i * 6) % 256, 40 + (i * 4) % 216, 120 + (i * 2) % 136, 255});
    //     }

    //     std::string s = std::to_string(counter);
    //     s.insert(s.begin(), 3 - s.size(), '0');

    //     screen.toFileExtension("img" + s + ".png");
    //     counter++;
    // }

    Color c;

    c.r = 0;
    c.g = 255;
    c.b = 0;

    screen.graphics.clear({0, 0, 0, 255});
    int XRES = screen.getWidth();
    int YRES = screen.getHeight();
    //octants 1 and 5
    screen.graphics.drawLine(0, 0, XRES - 1, YRES - 1, c);
    screen.graphics.drawLine(0, 0, XRES - 1, YRES / 2, c);
    screen.graphics.drawLine(XRES - 1, YRES - 1, 0, YRES / 2, c);

    //octants 8 and 4
    c.b = 255;
    screen.graphics.drawLine(0, YRES - 1, XRES - 1, 0, c);
    screen.graphics.drawLine(0, YRES - 1, XRES - 1, YRES / 2, c);
    screen.graphics.drawLine(XRES - 1, 0, 0, YRES / 2, c);

    //octants 2 and 6
    c.r = 255;
    c.g = 0;
    c.b = 0;
    screen.graphics.drawLine(0, 0, XRES / 2, YRES - 1, c);
    screen.graphics.drawLine(XRES - 1, YRES - 1, XRES / 2, 0, c);

    //octants 7 and 3
    c.b = 255;
    screen.graphics.drawLine(0, YRES - 1, XRES / 2, 0, c);
    screen.graphics.drawLine(XRES - 1, 0, XRES / 2, YRES - 1, c);

    //horizontal and vertical
    c.b = 0;
    c.g = 255;
    screen.graphics.drawLine(0, YRES / 2, XRES - 1, YRES / 2, c);
    screen.graphics.drawLine(XRES / 2, 0, XRES / 2, YRES - 1, c);

    screen.display();
    screen.toFileExtension("lines.png");
    screen.toFile("binary.ppm");
    screen.toFileAscii("ascii.ppm");

    return 0;
}