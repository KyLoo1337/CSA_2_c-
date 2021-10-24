//
// Created by vlado on 24.10.2021.
//

#ifndef TRIANGLE_CPP_TETRAHEDRON_H
#define TRIANGLE_CPP_TETRAHEDRON_H

#include <iostream>
#include "Figure.h"

class Tetrahedron : public Figure {
    int edge;
    int num = 3;

public:
    Tetrahedron(int edge, double density);
    double V() override;
    void To_String(std::string outPath) override;
};


#endif //TRIANGLE_CPP_TETRAHEDRON_H
