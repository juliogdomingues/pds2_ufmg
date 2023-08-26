#ifndef PDS2_SISTEMA_H
#define PDS2_SISTEMA_H

#include <map>
#include <string>

#include "cliente.h"
#include "frota.h"

class cliente_ja_existe_e {};
class cliente_nao_existe_e {};
class sem_saldo_e {};
class preco_corrida_negativo {};

/*
 * A classe sistema está ok de métodos e tads utilizados. Porém, ainda tem
 * tarefas aqui.
 *
 * TODO: 1. Faça um novo construtor que recebe o preco da corrida.
 *          - Crie uma nova exceção e lançe a mesma se o preço for <= 0.
 *       2. Documentar essa classe.
 *       3. Garantir que não tem bugs nem leaks
 */
class Sistema {
    private:
        std::map<std::string, Cliente *> _clientes;
        std::map<unsigned int, std::string > _carros_alocados;
        Frota _frota;
        double _preco_corrida;
    public:
        /*
         * @brief Construtor da classe, recebe o preço da corrida.
         * @throws Lança uma exceção se o preço for negativo.
         */
        Sistema(double preco_corrida);
        
        /*
         * @brief Adiciona um carro à frota.
         * Recebe a cor e o id do carro.
         */
        void adicionar_carro(std::string cor, unsigned int id);
        
        /*
         * @brief Cadastra um Cliente no sistema.
         * @throws Lança uma exceção se já houver cliente com o mesmo nome.
         */
        Cliente *cadastra_cliente(std::string nome);
        
        /*
         * @brief Busca um Carro para o Cliente.
         * Recebe o nome do Cliente.
         * @throws Lança uma exceção se n˜o houver Cliente com esse nome.
         * @throws Lança uma exceção se o cliente não tiver saldo para a corrida.
         * @throws Lança uma exceção se não houver carros disponíveis.
         */
        Carro *busca_uber(std::string nome);
        
        /*
         * @brief Destrutor.
         */
        ~Sistema();
};

#endif