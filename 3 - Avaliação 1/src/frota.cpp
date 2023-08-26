#include <iostream>

#include "../include/frota.h"

void Frota::cadastrar_carro(std::string cor, unsigned int id) {
    for (int i = 0; i < _carros.size(); i++) {
        if (_carros[i].get_id() == id) {
            throw  id_ja_existe_e();
            return;
        }
    }
    Carro c = Carro(cor, id);
    _carros.push_back(c);
}

Carro *Frota::alocar_carro() {
    if (_carros.empty()) {
        throw zero_carros_disponiveis_e();
    }
    
    for (int i = 0; i < _carros.size(); i++) {
        if (_carros[i].ocupado() == false) {
            _carros[i].seta_ocupado();
            return &_carros[i];
        }
    }
    throw zero_carros_disponiveis_e();
}