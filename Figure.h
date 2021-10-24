//
// Created by vlado on 24.10.2021.
//

#ifndef TRIANGLE_CPP_FIGURE_H
#define TRIANGLE_CPP_FIGURE_H
#include <iostream>

class Figure {

public:
    Figure(double density);

    virtual void To_String(std::string outPath);
    virtual double V();
    double density;
};


#endif //TRIANGLE_CPP_FIGURE_H
