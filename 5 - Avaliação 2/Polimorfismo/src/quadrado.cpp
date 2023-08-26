#include <iostream>

#include "../include/forma.h"
#include "../include/forma2d.h"
#include "../include/quadrado.h"

double Quadrado::get_area() {
    return _lado * _lado;
}

double Quadrado::get_perimetro() {
    return _lado * 4.0;
}