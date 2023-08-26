#include <string>

#include "../include/carro.h"

Carro::Carro(std::string cor, unsigned int id) {
    _cor = cor;
    _id = id;
}

std::string Carro::get_cor() {
    return _cor;
}

unsigned int Carro::get_id() {
    return _id;
}

void Carro::seta_ocupado() {
    this->_ocupado = true;
}

bool Carro::ocupado() {
    return _ocupado;
}