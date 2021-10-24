//
// Created by vlado on 24.10.2021.
//
#include <math.h>
#include <fstream>
#include <iostream>
#include "Ball.h"

# define M_PI           3.14159265358979323846  /* pi */

Ball::Ball(int r, double density) : Figure(density) {
    this->r = r;
}

double Ball::V() {
    return (4 * M_PI * r * r);
}

void Ball::To_String(std::string outPath) {
    std::ofstream fileOut;
    fileOut.open (outPath);
    fileOut << "1\n"
                 "Ball\n"
                 "R = " << r << "\n"
                                "density = " << density <<"\n"
                                "surface area = " << V() << std::endl;
    fileOut.close();
}
