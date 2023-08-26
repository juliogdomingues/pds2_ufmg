#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

/**
 * @brief The Package class represents a basic package for delivery.
 * 
 * This class provides a generic representation of a package with essential attributes and functionality.
 */
class Package {
protected:
    std::string _nome; /**< The name of the recipient. */
    std::string _endereco; /**< The address of the recipient. */
    unsigned int _peso; /**< The weight of the package in kilograms. */
    unsigned int _custo_por_quilo; /**< The cost per kilogram for delivery. */
    
public:
    Package() {}; /**< Default constructor. */
    
    /**
     * @brief Constructs a Package object with the specified parameters.
     * 
     * @param peso The weight of the package in kilograms.
     * @param custo_por_quilo The cost per kilogram for delivery.
     * @param nome The name of the recipient.
     * @param endereco The address of the recipient.
     */
    Package(unsigned int peso, unsigned int custo_por_quilo, const std::string& nome, const std::string& endereco) {
        _peso = peso;
        _custo_por_quilo = custo_por_quilo;
        _nome = nome;
        _endereco = endereco;
    };
    
    /**
     * @brief Gets the name of the recipient.
     * 
     * @return The name of the recipient.
     */
    std::string get_nome() const;
    
    /**
     * @brief Gets the weight of the package.
     * 
     * @return The weight of the package in kilograms.
     */
    unsigned int get_peso();
    
    /**
     * @brief Gets the cost per kilogram for delivery.
     * 
     * @return The cost per kilogram for delivery.
     */
    unsigned int get_custo_por_quilo();
    
    /**
     * @brief Calculates the total cost of the package delivery.
     * 
     * This method calculates the total cost of delivering the package
     * based on its weight and the cost per kilogram.
     * 
     * @return The total cost of the package delivery.
     */
    virtual double calculate_cost();
    
    virtual ~Package() {}; /**< Virtual destructor to allow proper cleanup in derived classes. */
};

#endif
