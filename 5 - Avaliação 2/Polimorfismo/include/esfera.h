#ifndef ESFERA_H
#define ESFERA_H

#include <iostream>
#include "forma.h"
#include "forma3d.h"

class Esfera : public Forma3D {
private:
    double _raio;
    std::string nome = "esfera";

public:
    Esfera(std::string cor, double raio) {
        _cor = cor;
        _nome = nome;
        _raio = raio;
    };
    double get_volume();
};

#endif
