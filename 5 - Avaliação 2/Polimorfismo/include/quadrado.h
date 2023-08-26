#ifndef QUADRADO_H
#define QUADRADO_H

#include <iostream>
#include "forma.h"
#include "forma2d.h"
#include "quadrado.h"


class Quadrado : public Forma2D {
private:
    double _lado;
    std::string nome = "quadrado";
public:
    Quadrado(std::string cor, double lado) {
        _cor = cor;
        _nome = nome;
        _lado = lado;
    };
    double get_area() override;
    double get_perimetro() override;
};

#endif
