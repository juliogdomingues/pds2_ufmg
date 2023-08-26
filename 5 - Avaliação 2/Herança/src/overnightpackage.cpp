#include "../include/package.h"
#include "../include/overnightpackage.h"

double OverNightPackage::calculate_cost() {
    return get_peso() * get_custo_por_quilo() + get_peso() * _adicional_noturno;
}

/*

A classe OvernightPackage deve herdar diretamente da classe 
Package e conter um membro de dados adicional para representar uma taxa 
adicional por quilo cobrado pelo serviço de entrega noturno.
OvernightPackage deve redefinir o método calculate_cost para 
que ela acrescente a taxa adicional por quilo ao custo-padrão por quilo
antes de calcular o custo da entrega.
*/