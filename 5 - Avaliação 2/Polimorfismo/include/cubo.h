#ifndef CUBO_H
#define CUBO_H

#include <iostream>
#include "forma.h"
#include "forma3d.h"

class Cubo : public Forma3D {
private:
    double _aresta;
    std::string nome = "cubo";

public:
    Cubo(std::string cor, double aresta) {
        _cor = cor;
        _nome = nome;
        _aresta = aresta;
    };
    double get_volume();
};

#endif
