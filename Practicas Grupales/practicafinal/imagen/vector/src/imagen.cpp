#include <cstring>
#include <string.h>
#include "imagen.h"

Imagen::Imagen(){
	nfilas=ncolumnas=0;
	datos=0;
}

Imagen::Imagen(int filas, int columnas){
	nfilas=filas;
	ncolumnas=columnas;

	datos=new byte[nfilas*ncolumnas];

	for(int i=0;i<filas*columnas;i++){
		apagar(datos[i]);
	}
}

void Imagen::copiarImagen(const Imagen &A, Imagen &B){
	for(int i=0;i<A.filas();i++){
		for(int j=0;j<A.columnas();j++)
			B.set(i,j,A.get(i,j));
	}
}

Imagen::Imagen(const Imagen &img){
	nfilas=img.nfilas;
	ncolumnas=img.ncolumnas;
	datos=new byte[nfilas*ncolumnas];

	copiarImagen(img,*this);
} 

Imagen Imagen::operator= (const Imagen &img){
	if(this!=&img){
		if(this->datos !=0){
			destruir();
		}
		nfilas=img.nfilas;
		ncolumnas=img.ncolumnas;

		datos=new byte[nfilas*ncolumnas];
	
		copiarImagen(img,*this);
	}

	return *this;
}


Imagen Imagen::operator+(const Imagen &img){
	int maximoFilas=0;

	if(this->filas()>img.filas())
		maximoFilas=this->filas();
	else	
		maximoFilas=img.filas();

	Imagen salida(maximoFilas,this->columnas()+img.columnas());

	// Solo mezclamos si ambas imagenes tienen tamaño >0, en caso contrario devolvemos una imagen en negro
	if(this->filas() > 0 && img.filas() > 0){
		for(int i=0;i<salida.filas();i++){
			for(int j=0;j<salida.columnas();j++){
				if(j<this->columnas()){
					if(i<this->filas())
						salida.set(i,j,this->get(i,j));
					else	
						salida.set(i,j,0);
				}
				else{
					if(i<img.filas())
						salida.set(i,j,img.get(i,j-this->columnas()));
					else
						salida.set(i,j,0);
				}
			}
		}
	}

	return salida;
}

void Imagen::crear(int filas, int columnas){
	if(datos !=0){
		destruir();
	}

	nfilas=filas;
	ncolumnas=columnas;

	datos=new byte[nfilas*ncolumnas];

	for(int i=0;i<nfilas*ncolumnas;i++){
		apagar(datos[i]);
	}
}

int Imagen::filas()const{
	return nfilas;
}

int Imagen::columnas()const{
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
	datos[y*columnas()+x]=v;	
}


byte Imagen::get(int y, int x)const{
	return datos[y*ncolumnas + x];
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

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario)const{
	bool resultado=false;
	if(esBinario){
		escribirPGMBinario(nombreFichero, datos,filas(),columnas());
		resultado=true;
	}else{
		escribirPGMTexto(nombreFichero, datos,filas(),columnas());
		resultado=true;
	}
	return resultado;
}

Imagen Imagen::plano(int k){
	Imagen salida= Imagen(filas(),columnas());
	
	for(int i=0;i < filas()*columnas();i++){
		if(getbit(getPos(i),k)){
			on(salida.datos[i],7);
		}
	}

	return salida;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){

	if(maxlong < nfilas*ncolumnas+nfilas+2){
		return false;
	}
	else{

		int longitudgrises= strlen(grises);
		int cont=0;
		byte b=0;

		for(int i=0;i< nfilas;i++){
			for(int j=0;j<ncolumnas;j++){
				b=get(i,j);
				arteASCII[cont]=grises[b*longitudgrises/256];
				cont++;
			}
			arteASCII[cont]='\n';
			cont++;
		}

		arteASCII[cont]='\n';
		arteASCII[cont+1]='\0';
		
	}
	return true;
}


bool Imagen::listaAArteASCII(const Lista &celdas){
	const int MAXTAM=this->filas()*(this->columnas()+1)+2;   	
	char *arteASCII= new char[MAXTAM]; 

	ofstream fsalida;
	string cadena;

	for(int i=0;i<celdas.longitud();i++){
		cadena = celdas.getCelda(i);
		aArteASCII(cadena.c_str(), arteASCII, MAXTAM);
		string nombre="arteASCII"+ to_string(i+1) +".txt";
		
		fsalida.open(nombre.c_str());

		fsalida <<  arteASCII<< endl;
		fsalida.close(); 
	}

	delete [] arteASCII;
	return true;
}

void Imagen::destruir(){
	nfilas=ncolumnas=0;

	if(datos !=0){
		delete [] datos;
	}
}


Imagen::~Imagen(){
  destruir();
}
