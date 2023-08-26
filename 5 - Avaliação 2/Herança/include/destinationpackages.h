#ifndef DEST_PACK_H
#define DEST_PACK_H

#include "package.h"

#include <map>
#include <string>
#include <vector>

class DestinationPackages : public Package {
private:
    std::map<std::string, std::vector<Package*>> packages_map; 

public:
    DestinationPackages(){};
    void add_package(Package* g);
    double custo_total() const;
    double custo_total(std::string nome_usuario) const;
};

#endif