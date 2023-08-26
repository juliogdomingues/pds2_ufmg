#ifndef FORMA3D_H
#define FORMA3D_H

#include <iostream>
#include "forma.h"

class Forma3D : public Forma {
protected:
    double _base;
    double _altura;
public:
    Forma3D() {};
    virtual double get_volume() = 0;
    std::string get_cor() override;
    std::string get_nome() override;
};

#endif
