#include <cstring>
#include <string.h>
#include "imagen.h"

void Imagen::copiarImagen(const Imagen &img1, Imagen &img2){

	img2.nfilas=img1.nfilas;
	img2.ncolumnas=img1.ncolumnas;
	img2.datos=new byte*[nfilas];
	img2.datos[0]=new byte[img2.nfilas*img2.ncolumnas];

	for(int i=1;i<img1.filas();i++)
		img2.datos[i] = img1.datos[0] + i*img1.columnas();

	for(int i=0;i<img1.filas();i++){
		for(int j=0;j<img1.columnas();j++)
			img2.datos[i][j]=img1.datos[i][j];
	}
}

void Imagen::crear(int filas, int columnas){
	if(datos!=0){
		delete [] datos[0];
		delete [] datos;
		datos=0;
	}
   	nfilas=filas;
   	ncolumnas=columnas;
   	datos=new byte*[nfilas];
   	datos[0]=new byte[nfilas*ncolumnas];

   	for(int i=1; i<nfilas; i++)
      		datos[i]=datos[i-1]+ncolumnas;

	for (int i=0; i < nfilas; i++){
		for (int j=0; j < ncolumnas; j++){
			apagar(datos[i][j]);
		}
	}
}

Imagen::Imagen(){
	nfilas=ncolumnas=0;
	datos=0;
}

Imagen::Imagen(int filas, int columnas){
	datos=0;
	crear(filas,columnas);
}


Imagen::Imagen(const Imagen &img){
	copiarImagen(img,*this);
} 

Imagen Imagen::operator=(const Imagen &img){
	
	if(this!=&img){	
		if(datos !=0){
			destruir();
		}
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

	for(int i=0; i<salida.filas(); i++){
		for (int j = 0; j < salida.columnas(); j++){
			if (filas() > img.filas()){ 
				if (j < columnas()){
					salida.set(i,j,get(i,j));
				}else if(i >= img.filas()){ 
					salida.set(i,j,0);
				}else{ 
					salida.set(i,j,img.get(i,j-columnas()));
				}
				
			}else{
				if (j > columnas()){ 
					salida.set(i,j,img.get(i,j-columnas()));
				}else if(i >= filas()){ 
					salida.set(i,j,0);
				}else{ 
					salida.set(i,j,get(i,j));
				}				
			}
		}
	}

	return salida;
}


int Imagen::filas()const{
	return nfilas;
}

int Imagen::columnas()const{
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
	int pos= y*ncolumnas+x;

	if(pos<nfilas*ncolumnas)
		datos[y][x]=v;	
}


byte Imagen::get(int y, int x)const{

	if(y<nfilas && y>= 0 && x >= 0 && x<ncolumnas)
		return datos[y][x];
	else
		return 0;
}

void Imagen::setPos(int i, byte v){
	if(i<nfilas*ncolumnas && i>=0){
		datos[i/ncolumnas][i%ncolumnas] = v;
	}
}

byte Imagen::getPos(int i){
	byte b;
	if(i<nfilas*ncolumnas && i>=0){
		b=datos[i/ncolumnas][i%ncolumnas];
	}
	return b;
}

bool Imagen::leerImagen(const char nombreFichero[]){
	bool resultado=false;
	TipoImagen tipo;
	int f,c;
	f=c=0;
	tipo=infoPGM(nombreFichero,f,c);

	crear(f,c);

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
	Imagen salida(filas(),columnas());
	
	for(int i=0;i < filas();i++){
		for(int j=0;j < columnas();j++){
			if(getbit(get(i,j),k)){
				on(salida.datos[i][j],7);
			}
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
	if(datos != 0){
		delete [] datos[0];
		delete [] datos;
		nfilas=0;
		ncolumnas=0;
	}
	
}


Imagen::~Imagen(){
  destruir();
}
