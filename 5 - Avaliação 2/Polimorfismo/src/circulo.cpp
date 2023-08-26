#include <iostream>
#include <math.h>

#include "../include/forma.h"
#include "../include/forma2d.h"
#include "../include/circulo.h"

double Circulo::get_area() {
    return M_PI * pow(_raio, 2);
}

double Circulo::get_perimetro() {
    return M_PI * _raio * 2;
}
