//
// Created by vlado on 24.10.2021.
//

#include <iostream>
#include <fstream>
#include "Parallelepiped.h"

double Parallelepiped::V() {
    return 2*(edgeLen[0]*edgeLen[1]+edgeLen[1]*edgeLen[2]+edgeLen[2]*edgeLen[0]);
}

Parallelepiped::Parallelepiped(int *edgeLen, double density) : Figure(density) {
    for(int i = 0; i < 3; ++i)
        this->edgeLen[i] = edgeLen[i];
    this->density = density;
}

void Parallelepiped::To_String(std::string outPath) {
    std::ofstream fileOut;
    fileOut.open (outPath);
    fileOut << "2\n"
                 "Parallelepiped\n"
                 "edges: " << edgeLen[0] << "; " << edgeLen[1] << "; " << edgeLen[2] << "\n"
                                                                                        "density = " << density <<"\n"
                                                                                                                    "surface area = " << V() << std::endl;
    fileOut.close();
}
