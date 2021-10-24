//
// Created by vlado on 24.10.2021.
//

#include <iostream>
#include <fstream>
#include "Figure.h"

Figure::Figure(double density) {
    this->density = density;
}

double Figure::V() {
    return 1;
}

void Figure::To_String(std::string outPath) {
    std::ofstream fileOut;
    fileOut.open (outPath);
    fileOut << "0\n"
                 "Figure\n"
                                "density = " << density << std::endl;
    fileOut.close();

}
