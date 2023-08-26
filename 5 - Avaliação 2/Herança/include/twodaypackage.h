#ifndef TWO_DAY_PACK_H
#define TWO_DAY_PACK_H

#include "package.h"

/**
 * @brief The TwoDayPackage class represents a specialized package for two-day delivery service.
 * 
 * This class extends the base Package class and incorporates a fixed fee for two-day deliveries.
 */
class TwoDayPackage : public Package {
private:
    unsigned int _taxa_fixa; /**< The fixed fee for two-day delivery service. */

public:
    /**
     * @brief Constructs a TwoDayPackage object with the specified parameters.
     * 
     * @param peso The weight of the package in kilograms.
     * @param custo_por_quilo The cost per kilogram for delivery.
     * @param taxa_fixa The fixed fee for two-day delivery.
     * @param nome The name of the recipient.
     * @param endereco The address of the recipient.
     */
    TwoDayPackage(unsigned int peso, unsigned int custo_por_quilo, unsigned int taxa_fixa, const std::string& nome, const std::string& endereco) {
        _peso = peso;
        _custo_por_quilo = custo_por_quilo;
        _nome = nome;
        _endereco = endereco;
        _taxa_fixa = taxa_fixa;
    };
    
    /**
     * @brief Calculates the total cost of the two-day package delivery.
     * 
     * This method overrides the base class's calculate_cost method and
     * adds the fixed fee for two-day delivery to the total cost of the delivery.
     * 
     * @return The total cost of the two-day package delivery.
     */
    double calculate_cost() override;
};

#endif
