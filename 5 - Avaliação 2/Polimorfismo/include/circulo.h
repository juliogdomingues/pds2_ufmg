#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include "forma.h"
#include "forma2d.h"

class Circulo : public Forma2D {
private:
    double _raio;
    std::string nome = "circulo";

public:
    Circulo(std::string cor, double raio) {
        _cor = cor;
        _nome = nome;
        _raio = raio;
    };
    double get_area() override;
    double get_perimetro() override;
};

#endif
