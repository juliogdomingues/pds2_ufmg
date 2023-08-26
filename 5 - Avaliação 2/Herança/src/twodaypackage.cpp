#include "../include/package.h"
#include "../include/twodaypackage.h"

double TwoDayPackage::calculate_cost() {
    return static_cast<double>(get_peso() * get_custo_por_quilo()) + _taxa_fixa;
}

/*
A classe derivada TwoDayPackage deve herdar a funcionalidade da
classe básica Package, mas também incluir um membro de dados que
representa uma taxa fixa que a empresa de entrega cobra pelo serviço
de entrega em dois dias. O construtor TwoDayPackage deve receber 
um valor para inicializar esse membro de dados.
TwoDayPackage deve redefinir o método calculate_cost para que ele
calcule o custo de entrega adicionando a taxa fixa ao custo baseado
em peso calculado pela função calculate_cost da super classe Package. 
*/