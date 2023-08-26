#include "../include/sistema.h"

Sistema::Sistema(double preco_corrida) {
    if (preco_corrida <= 0) {
        throw preco_corrida_negativo();
    }
    _preco_corrida = preco_corrida;
}

Cliente *Sistema::cadastra_cliente(std::string nome) {
    if (_clientes.count(nome) > 0) {
        throw cliente_ja_existe_e();
    }

    Cliente *cliente = new Cliente(nome);
    _clientes[nome] = cliente;
    return cliente;
}

void Sistema::adicionar_carro(std::string cor, unsigned int id) {
    _frota.cadastrar_carro(cor, id);
}

Carro* Sistema::busca_uber(std::string nome) {
    if (_clientes.count(nome) <= 0) {
        throw cliente_nao_existe_e();
    }

    Cliente* c = _clientes.at(nome);

    if (c->get_saldo() == 0) {
        throw sem_saldo_e();
    }

    if (c->get_saldo() < _preco_corrida) {
        throw sem_saldo_e();
    }

    Carro *car = _frota.alocar_carro();
    return car;
}

Sistema::~Sistema() {
    for (auto it = _clientes.begin(); it != _clientes.end(); it++) {
        delete it->second;
    }
}