#include "circulo.h"

void EscribirCirculo(const Circulo &p){
	cout << p.radio <<"-( "<< p.centro.x << ","<< p.centro.x <<  ") "<< endl;

}

Circulo LeerCirculo(){
	Circulo c;
	cout << "Introduce Radio:"<<endl;
	cin >> c.radio;
	cout << "Introduce Punto:"<<endl;
	c.centro=LeerPunto();

	return c;
}

double AreaCirculo(const Circulo &c){
	return M_PI*c.radio*c.radio;

}