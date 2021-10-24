//
// Created by vlado on 24.10.2021.
//

#include <math.h>
#include <iostream>
#include <fstream>
#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(int edge, double density) : Figure(density) {
    this->edge=edge;
}

double Tetrahedron::V() {
    return sqrt(3)*edge;
}

void Tetrahedron::To_String(std::string outPath) {
    std::ofstream fileOut;
    fileOut.open (outPath);
    fileOut << "3\n"
                 "Tetrahedron\n"
                 "edge = " << edge << "\n"
                                "density = " << density <<"\n"
                                                          "surface area = " << V() << std::endl;
    fileOut.close();
}
