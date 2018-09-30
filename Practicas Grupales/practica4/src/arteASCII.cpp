//lee imagenes/gio.txt y la convierte en ascii con los conjuntos de caracteres contenidos en nombreConjunto
#include<iostream>
#include<imagen.h>
#include<fstream>
#include<string.h>

using namespace std;


const int MAXLONG = 1000000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main(){
    char grises[MAXLONG];
    char arteASCII[MAXLONG]; 
    char nombreImagen[MAXLONG];
    char nombreFichero[MAXLONG];
    char nombreSalida[MAXLONG];
    char nombreConjunto[MAXLONG];
    Imagen origen;

	cout << "Introduzca nombre de la imagen: ";
	leelinea(nombreImagen);


    // Leer la imagen gio.txt
    if (!origen.leerImagen(nombreImagen)){
		cerr << "error leyendo imagen" << nombreImagen << endl;
	   return 1;
    }
	
	cout << "Introduzca el nombre del fichero con el conjunto de caracteres: ";
	leelinea(nombreFichero);
	cout << "Intorduzca nombre de salida: ";
	leelinea(nombreSalida);
	
	char cadena[MAXLONG];

	ifstream fentrada;
	ofstream fsalida;
	fentrada.open(nombreFichero);
	
	int contadorNombre=1;
	int numero_grises;
	char nombreSalidaA[MAXLONG];

	fentrada.getline(cadena,MAXLONG); //1º Linea de comentario
	fentrada >> numero_grises; //Numero de lineas de grises en el fichero
	fentrada.getline(cadena,MAXLONG); //consume la linea de grises en el fichero

	for(int i=0;i<numero_grises;i++){
		fentrada.getline(cadena,MAXLONG);

		sprintf (nombreSalidaA, "%s %d.txt", nombreSalida,contadorNombre);
		fsalida.open(nombreSalidaA);

		fsalida << "\nLa imagen en arte ASCII es:\n";
		if(origen.aArteASCII(cadena, arteASCII, MAXLONG-1)){
		        fsalida <<  arteASCII<< endl;
		        contadorNombre++;
		}else{
		        fsalida << "La conversión no ha sido posible" << endl; 
		}
		fsalida.close(); 
	}
	fentrada.close();


	
}
