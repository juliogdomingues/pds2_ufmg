#include "../include/package.h"
#include "../include/destinationpackages.h"
#include "../include/overnightpackage.h"
#include "../include/twodaypackage.h"

#include <iostream>
#include <map>
#include <string>

void DestinationPackages::add_package(Package* g) {
    packages_map[g->get_nome()].push_back(g);

}

double DestinationPackages::custo_total() const {
    double custo_todos_usuarios = 0.0;
    for (const auto& pair : packages_map) {
        for (Package* pack : pair.second) {
            custo_todos_usuarios += pack->calculate_cost();
        }
    }
    return custo_todos_usuarios;
}

double DestinationPackages::custo_total(std::string nome_usuario) const {
    double custo_usuario = 0;
    if (packages_map.count(nome_usuario) > 0) {
        for (Package* pack : packages_map.at(nome_usuario)) {
            custo_usuario += (pack->calculate_cost());
        }
    }
    return custo_usuario;
}

/*
Crie também uma classe DestinationPackages que armazena para 
cada destinatário os seus Packages.
A classe deve conter um map de vectors (std::map<string, vector<Package*> >)
que armazena um vetor do tipo mais abstrato Package no valor, indexando
pelo nome do destinatário na chave.
Note que o vetor é de ponteiros para fazer uso de polimorfismo.
Sua classe deve ter um método void add_package(Package g) que guarda
um novo pacote no mapa.
A mesma, também deve ter dois métodos com o mesmo nome double custo_total() 
que realiza um loop para processar o Packages polimorficamente.
A primeira variação double custo_total() computa o custo de todos os usuários,
enquanto a segunda double custo_total(string) computa os custos de um único usuário.
*/