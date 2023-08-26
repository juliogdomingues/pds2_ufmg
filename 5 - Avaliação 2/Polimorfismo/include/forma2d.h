#ifndef FORMA2D_H
#define FORMA2D_H

#include <iostream>
#include <vector>
#include "forma.h"

class Forma2D : public Forma {
protected:
    std::vector<double> _lados;
public:
    Forma2D() {};
    std::string get_cor() override;
    std::string get_nome() override;
    virtual double get_area() = 0;
    virtual double get_perimetro() = 0;
};

#endif
