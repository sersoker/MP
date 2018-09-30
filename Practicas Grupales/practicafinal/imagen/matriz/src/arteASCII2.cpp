/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas 
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "imagen.h"
#include "lista.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    Imagen origen;
    Lista celdas;

    if(argc!=3){
		cerr << "Error en el numero de parametros " << endl;
		return 1;
    }

    // Leer la imagen desde fichero
    if (!origen.leerImagen(argv[1])){
		cerr << "Error leyendo imagen " << argv[1] << endl;
		return 1;
    }


	if (celdas.leerLista(argv[2])){	
		// realizar las conversiones
		if (origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros .txt" << endl;
		}else{
			cerr << "La conversion no ha sido posible" << endl;
		}
	}else{
		cerr << "Error lista de grises " << argv[2] << endl;
	}

return 0;
}
