#include <iostream>
#include <math.h>

#include "../include/forma.h"
#include "../include/forma2d.h"
#include "../include/triangulo.h"

double Triangulo::get_area() {
    double semi_perimetro = (_aresta_1 + _aresta_2 + _aresta_3) / 2.0;
    double area = std::sqrt(semi_perimetro * (semi_perimetro - _aresta_1) * (semi_perimetro - _aresta_2) * (semi_perimetro - _aresta_3));
    return area;
}

double Triangulo::get_perimetro() {
    return _aresta_1 + _aresta_2 + _aresta_3;
}