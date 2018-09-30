/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas 
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include <iostream>
#include "imagen.h"
#include "lista.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    Imagen B;
    Imagen C;

//Comentar y descomentar
   // Imagen A;

    if(argc!=5){
		cerr << "Error en el numero de parametros " << endl;
		return 1;
    }else{

	    // Leer la imagen desde fichero
	    if (!B.leerImagen(argv[1])){
			cerr << "Error leyendo imagen " << argv[1] << endl;
			return 1;
	    }

	    if (!C.leerImagen(argv[2])){
			cerr << "Error leyendo imagen " << argv[2] << endl;
			return 1;
	    }

//Comentar una, descomentar la otra
    	Imagen A=B+C;
    	//A=B+C;

	    if(argv[4]== string("t")){
			A.escribirImagen(argv[3],false);
	    }else if(argv[4] == string("b")){
			A.escribirImagen(argv[3],true);	
	    }else{
  		cerr << "Error en el parametro indicando binario o texto" << endl;
	    }

     }

     return 0;
}
