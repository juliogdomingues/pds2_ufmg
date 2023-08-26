#include <iostream>
#include <math.h>

#include "../include/forma.h"
#include "../include/forma3d.h"
#include "../include/esfera.h"

double Esfera::get_volume() {
    return (4.0/3.0) * M_PI * pow(_raio, 3); 
}
