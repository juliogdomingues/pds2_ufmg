#include <iostream>
#include <math.h>

#include "../include/forma.h"
#include "../include/forma3d.h"
#include "../include/cubo.h"

double Cubo::get_volume() {
    return pow(_aresta, 3);
}

