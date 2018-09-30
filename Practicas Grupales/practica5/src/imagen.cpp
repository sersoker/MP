#include <cstring>
#include "imagen.h"

const int MAXLONG = 1000000;

Imagen::Imagen(){
	nfilas=ncolumnas=0;
	datos=0;
}

Imagen::Imagen(int filas, int columnas){
	nfilas=filas;
	ncolumnas=columnas;

	datos=new byte[nfilas*ncolumnas];

	for(int i=0;i<filas*columnas;i++){
		datos[i]=0;
	}
}

void Imagen::crear(int filas, int columnas){
	if(datos !=0){
		destruir();
	}

	nfilas=filas;
	ncolumnas=columnas;

	datos=new byte[nfilas*ncolumnas];

	for(int i=0;i<filas*columnas;i++){
		datos[i]=0;
	}
}

int Imagen::filas(){
	return nfilas;
}

int Imagen::columnas(){
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
	int posicion;
	if(y==0)
		posicion=x;
	else
		posicion=(y*ncolumnas)+x;
	
	datos[posicion]=v;		
}


byte Imagen::get(int y, int x){
	if(y==0)
		return datos[x];
	else
		return datos[y*ncolumnas+x];
}

void Imagen::setPos(int i, byte v){
	datos[i]=v;
}

byte Imagen::getPos(int i){
	return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
	bool resultado=false;
	TipoImagen tipo;
	int f,c;
	f=c=0;
	tipo=infoPGM(nombreFichero,f,c);

	this->crear(f,c);

	if(tipo==IMG_PGM_BINARIO&&f*c<this->MAXPIXELS){
		leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);
		resultado=true;
	}else if(tipo==IMG_PGM_TEXTO&&f*c<this->MAXPIXELS){
		leerPGMTexto(nombreFichero,datos,nfilas,ncolumnas);
		resultado=true;
	}

	return resultado;
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
	bool resultado=false;
	if(esBinario){
		escribirPGMBinario(nombreFichero, datos,nfilas,ncolumnas);
		resultado=true;
	}else{
		escribirPGMTexto(nombreFichero, datos,nfilas,ncolumnas);
		resultado=true;
	}
	return resultado;
}

Imagen Imagen::plano(int k){
	Imagen salida= Imagen(nfilas,ncolumnas);
	
	for(int i=0;i < nfilas*ncolumnas;i++){
		if(getbit(this->datos[i],k)){
			on(salida.datos[i],7);
		}
	}

	return salida;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){

	int ultimo=0;
	if(maxlong < nfilas*ncolumnas+nfilas+2)
		return false;
	else{
		int longitudgrises= strlen(grises)-1; // -1 por el **** /n
		//cerr << "<" << grises << ">" << endl;
		//cout << "Cardinal grises:" << longitudgrises << endl;

		int cont=0;

		for(int i=0;i< nfilas*ncolumnas+nfilas;i++){
			if(i%(ncolumnas)==0){
				arteASCII[i+cont]='\n';
				cont++;	
			}			
			arteASCII[i+cont]=grises[datos[i]*longitudgrises/256];
			ultimo=i;
		}

		arteASCII[ultimo+1]='\n';
		arteASCII[ultimo+2]='\0';
		
	}
	return true;
}

void leelinea2(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

bool Imagen::listaAArteASCII(const Lista celdas){
    char nombreSalida[MAXLONG];
	char arteASCII[MAXLONG]; 

	cout << "Introduzca nombre de salida: ";
	leelinea2(nombreSalida);

	ofstream fsalida;
	
	int contadorNombre=1;
	int numero_grises=0;
	char nombreSalidaA[MAXLONG];


	for(int i=0;i<celdas.longitud();i++){
		sprintf (nombreSalidaA, "%s %d.txt", nombreSalida,contadorNombre);
		fsalida.open(nombreSalidaA);
		fsalida << "\nLa imagen en arte ASCII es:\n";
		if(aArteASCII(celdas.getCelda(i).c_str(), arteASCII, MAXLONG-1)){
		        fsalida <<  arteASCII<< endl;
		        contadorNombre++;
		}else{
		        fsalida << "La conversión no ha sido posible" << endl; 
		}
		fsalida.close(); 
	}
}

void Imagen::destruir(){
	nfilas=ncolumnas=0;

	if(datos !=0){
		delete [] datos;
		datos=0;
	}
}


Imagen::~Imagen(){
  destruir();
}
