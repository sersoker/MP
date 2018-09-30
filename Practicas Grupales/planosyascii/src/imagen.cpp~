#include "imagen.h"

Imagen::Imagen(){
	nfilas=ncolumnas=0;
}

Imagen::Imagen(int filas, int columnas){
	nfilas=filas;
	ncolumnas=columnas;
	for(int i=0;i<filas*columnas;i++){
		datos[i]=0;
	}
}

void Imagen::crear(int filas, int columnas){
	nfilas=filas;
	ncolumnas=columnas;
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
	tipo=infoPGM(nombreFichero,f,c);
	if(tipo==IMG_PGM_BINARIO&&f*c<MAXPIXELS){
		leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);
		resultado=true;
	}


return resultado;
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
	bool resultado=false;
	if(esBinario){
		escribirPGMBinario (nombreFichero, datos,nfilas,ncolumnas);
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

		int longitudgrises=0;
		for(int i=0; grises[i]!='\0';i++){
			longitudgrises++;
		}

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
