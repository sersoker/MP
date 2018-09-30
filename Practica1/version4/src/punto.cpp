#include "punto.h"

// Implementación de las funciones
void EscribirPunto(const Punto &p){
	cout << "( "<< p.x << ","<< p.x <<  ") "<< endl;
}

Punto LeerPunto(){
	Punto p;
	cout << "Introduce punto: (Coordenada x)"<<endl;
	cin >> p.x;
	cout << "Introduce punto: (Coordenada y)"<<endl;
	cin >> p.y;

	return p;
}

double DistanciaPuntos(const Punto &p1, const Punto &p2){

	return sqrt(((p2.x-p1.x)*(p2.x-p1.x))+((p2.y-p1.y)*(p2.y-p1.y)));

}

Punto PuntoMedio(const Punto &p1, const Punto &p2){
	Punto p;
	p.x=(p1.x+p2.x)/2;
	p.y=(p1.y+p2.y)/2;
	return p;
}
