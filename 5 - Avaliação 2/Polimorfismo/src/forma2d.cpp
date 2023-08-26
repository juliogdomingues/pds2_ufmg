#include <iostream>

#include "../include/forma.h"
#include "../include/forma2d.h"

std::string Forma2D::get_cor() {
    return _cor;
}

std::string Forma2D::get_nome() {
    return _nome;
};

double Forma2D::get_perimetro() {
    double soma = 0.0;
    for (double lado : _lados) {
        soma += lado;
    }
    return soma;
}