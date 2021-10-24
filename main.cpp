//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include<vector>
#include <sstream>
#include <algorithm>    // std::count

using namespace std;

int switchable_number(const string& str) {
    if (str == "1") {
        return 1;
    } else if (str == "2") {
        return 2;
    } else if (str == "3") {
        return 3;
    } else {
        return 0;
    }
}

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void swap(Figure * *a, Figure * *b) {
    Figure* temp = *a;
    *a = *b;
    *b = temp;
}

// ShakerSort from terms of reference.
vector<Figure*> ShakerSort(vector<Figure*> a, int n)
{
    int i, j, k;
    for(i = 0; i < n;)
    {
        for(j = i+1; j < n; j++)
        {
            if(a[j]->V() > a[j-1]->V())
                swap(&a[j], &a[j-1]);
        }
        n--;

        for(k = n-1; k > i; k--)
        {
            if(a[k]->V() > a[k-1]->V())
                swap(&a[k], &a[k-1]);
        }
        i++;
    }
    return a;
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 3) {
        errMessage1();
        return 1;
    }
    vector<Figure*> figures;

    cout << "Start"<< endl;

    ifstream inf(argv[2]);

    if (!inf)
    {
        errMessage2();
        exit(1);
    }

    while (inf)
    {
        string num, density;
        getline(inf, num);
        int numInt = switchable_number(num);
        switch (numInt) {
            case 1:
            {
                string r;
                getline(inf, r);
                getline(inf, density);
                figures.push_back(new Ball(stoi(r), stof(density)));
                break;
            }
            case 2: {
                string edges;
                getline(inf, edges);
                getline(inf, density);
                string edges_arr_string[3];
                int i = 0;
                stringstream ssin(edges);
                while (ssin.good() && i < 3) {
                    ssin >> edges_arr_string[i];
                    ++i;
                }
                int edges_arr_int[3];
                for (i = 0; i < 3; ++i)
                    edges_arr_int[i] = stoi(edges_arr_string[i]);
                figures.push_back(new Parallelepiped(edges_arr_int, stof(density)));
                break;
            }
            case 3: {
                string edge;
                getline(inf, edge);
                getline(inf, density);
                figures.push_back(new Tetrahedron(stoi(edge), stof(density)));
                break;
            }
            default:
                break;
        }
    }
    figures = ShakerSort(figures, figures.size());
    for(int i = 0; i < figures.size(); ++i)
      figures[i]->To_String();
    return 0;
}
