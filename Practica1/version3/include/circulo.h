#ifndef _CIRCULO_H_
#define _CIRCULO_H_

#include <iostream>
#include <cmath> 
#include "punto.h"
using namespace std;


struct Circulo {
    Punto centro; 
    double radio; 
};

// Prototipos de las funciones
void EscribirCirculo(const Circulo &c); 
Circulo LeerCirculo(); 
double AreaCirculo(const Circulo &c);

#endif