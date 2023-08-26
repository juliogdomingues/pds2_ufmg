#include <string>

#include "../include/package.h"

std::string Package::get_nome() const {
    return _nome;
}

unsigned int Package::get_peso() {
    return _peso;
}

unsigned int Package::get_custo_por_quilo() {
    return _custo_por_quilo;
}

double Package::calculate_cost() {
    return _peso * _custo_por_quilo;
}

// Package::~Package() {

// }

/*
Utilize Package como a classe básica da hierarquia, então inclua as
classes TwoDayPackage e OvernightPackage que derivam de Package.
A classe básica Package deve incluir membros de dados que representam 
nome e endereço. Para simplificar nosso código, represente o endereço 
como uma ́única string. Além dos membros de citados anteriormente, armazen
e dados que armazenam o peso (em quilos) e o custo por quilo para a 
entrega do pacote. O construtor Package deve inicializar todos os membros 
de dados, em outras palavras, todos são argumentos do construtor.
Assegure que o peso e o custo por quilo contenham valores positivos
(faça uso de unsigned int).
Package deve fornecer um método public calculate_cost que retorna um 
double indicando o custo associado com a entrega do pacote.
A função calculate_cost de Package deve determinar o custo multiplicando
o peso pelo custo(em quilos). 
*/