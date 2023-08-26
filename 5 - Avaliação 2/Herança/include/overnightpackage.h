#ifndef OVERNIGHT_PACK_H
#define OVERNIGHT_PACK_H

#include "package.h"

/**
 * @brief The OverNightPackage class represents a specialized package for overnight delivery service.
 * 
 * This class extends the base Package class and incorporates an additional fee for nighttime deliveries.
 */
class OverNightPackage : public Package {
private:
    unsigned int _adicional_noturno; /**< The additional per-kilogram fee for overnight delivery service. */

public:
    /**
     * @brief Constructs an OverNightPackage object with the specified parameters.
     * 
     * @param peso The weight of the package in kilograms.
     * @param custo_por_quilo The standard cost per kilogram for delivery.
     * @param adicional_noturno The additional fee per kilogram for overnight delivery.
     * @param nome The name of the recipient.
     * @param endereco The address of the recipient.
     */
    OverNightPackage(unsigned int peso, unsigned int custo_por_quilo, unsigned int adicional_noturno, const std::string& nome, const std::string& endereco) {
        _peso = peso;
        _custo_por_quilo = custo_por_quilo;
        _nome = nome;
        _endereco = endereco;
        _adicional_noturno = adicional_noturno;
    };

    /**
     * @brief Calculates the total cost of the overnight package delivery.
     * 
     * This method overrides the base class's calculate_cost method and
     * adds the additional fee per kilogram to the standard per-kilogram cost
     * before calculating the total cost of the delivery.
     * 
     * @return The total cost of the overnight package delivery.
     */
    double calculate_cost() override;
};

#endif
