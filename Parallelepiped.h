//
// Created by vlado on 24.10.2021.
//

#ifndef TRIANGLE_CPP_PARALLELEPIPED_H
#define TRIANGLE_CPP_PARALLELEPIPED_H

#include <iostream>
#include "Figure.h"

class Parallelepiped : public Figure {
    int edgeLen [3]{};
    int num = 2;

public:
    Parallelepiped(int *edgeLen, double density);
    double V() override;
    void To_String(std::string outPath) override;
};


#endif //TRIANGLE_CPP_PARALLELEPIPED_H
