#include <iostream>
using namespace std;

struct Tiempo{
	int horas;
	int minutos;
	int segundos;

};


Tiempo segundosAHoras(int s){
	Tiempo salida;

	int segundosAlmacenados=s;
		salida.horas=(segundosAlmacenados/3600)%24;
	segundosAlmacenados=segundosAlmacenados%3600;
		salida.minutos=segundosAlmacenados/60;
	segundosAlmacenados=segundosAlmacenados%60;

	salida.segundos=segundosAlmacenados;


	return salida;
}

int convertirASegundos(Tiempo t){
	int salida=0;

	salida+=(t.horas*3600);
	salida+=t.minutos*60;
	salida+=t.segundos;

	return salida;
}


bool esPosterior(Tiempo t1, Tiempo t2){
	return convertirASegundos(t1)<convertirASegundos(t2);

}



Tiempo obtenerNuevoTiempo(Tiempo t, int s){

	int TiempoSeg=convertirASegundos(t)+s;
	return segundosAHoras(TiempoSeg);

}

int main(){

	Tiempo t1={23,2,3};
	Tiempo t2={1,2,3};
	Tiempo t3={2,2,3};


cout << "ComparandoTiempos:"<<endl;
	if(esPosterior(t1,t2))
		cout << "DEVUELVE TRUE"<<endl;
	else
		cout << "DEVUELVE False"<<endl;

	if(esPosterior(t2,t3))
		cout << "DEVUELVE TRUE"<<endl;
	else
		cout << "DEVUELVE False"<<endl;

	if(esPosterior(t1,t3))
		cout << "DEVUELVE TRUE"<<endl;
	else
		cout << "DEVUELVE False"<<endl;

cout << "Tiempo 2 en segundos:"<<convertirASegundos(t2)<<endl;

Tiempo t4=obtenerNuevoTiempo(t1,3600);
cout << "Horas: "<<t4.horas<<" Minutos:"<<t4.minutos<<" Segundos:"<<t4.segundos<<endl;

}