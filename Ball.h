//
// Created by vlado on 24.10.2021.
//

#ifndef TRIANGLE_CPP_BALL_H
#define TRIANGLE_CPP_BALL_H

#include <iostream>
#include "Figure.h"

class Ball : public Figure {
    int r;
    int num = 0;

public:
    Ball(int r, double density);
    double V() override;
    void To_String(std::string outPath) override;
};


#endif //TRIANGLE_CPP_BALL_H
