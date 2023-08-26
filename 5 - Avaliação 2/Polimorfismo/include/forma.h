#ifndef FORMA_H
#define FORMA_H

#include <iostream>

class Forma {
protected:
    std::string _cor;
    std::string _nome;
    
public:
    Forma() {};
    Forma(std::string cor) : _cor(cor) {};
    Forma(std::string cor, std::string nome) : _cor(cor), _nome(nome) {};
    virtual std::string get_cor() = 0;
    virtual std::string get_nome() = 0;
};

#endif
