#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <iostream>
#include "forma.h"
#include "forma2d.h"

class Triangulo : public Forma2D {
private:
    double _aresta_1;
    double _aresta_2;
    double _aresta_3;
    std::string nome = "triangulo";
public:
    Triangulo(std::string cor, double aresta_1, double aresta_2, double aresta_3) {
        _cor = cor;
        _nome = nome;
        _aresta_1 = aresta_1;
        _aresta_2 = aresta_2;
        _aresta_3 = aresta_3;
    };
    double get_area() override;
    double get_perimetro() override;
};

#endif
