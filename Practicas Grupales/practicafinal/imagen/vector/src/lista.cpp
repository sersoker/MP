#include <string>
#include <fstream>
#include <iostream>
#include "lista.h"

using namespace std;

Lista::Lista(){
	this->cabecera=0;
}
   
Lista::Lista(string valor){
	this->cabecera=new Celda();
	this->cabecera->datos=valor;
	this->cabecera->siguiente=0;
}
	
Lista::Lista(const Lista &list){
	if(list.cabecera!=0){
		Celda *pCelda=this->cabecera;
		Celda *pLista=list.cabecera;
		pCelda=new Celda();
		

		while(pLista!=0){
			pCelda->datos=pLista->datos;
			pLista=pLista->siguiente;
			if(pLista!=0){
				pCelda->siguiente=new Celda();
				pCelda=pCelda->siguiente;
			}
		}
	}

} 
   

Lista::~Lista(){
	this->destruir();
}
   


Lista Lista::operator+(const Lista &list){
	Lista l(*this);
	Celda *pCelda =list.cabecera;

	while(pCelda!=0){
		l.insertar(pCelda->datos);
		pCelda=pCelda->siguiente;
	}
	return l;
}



void Lista::destruir(){
	Celda *ptr=cabecera;
	Celda *siguiente=cabecera;

	while(ptr != 0){
		siguiente=ptr->siguiente;
		delete ptr;
		ptr=siguiente;
	}
}  

void Lista::insertar(string valor){
	Celda *ptr=cabecera;
	
	if(cabecera != 0){
		while(ptr->siguiente != 0){
			ptr=ptr->siguiente;
		}

		ptr->siguiente=new Celda();
		ptr->siguiente->datos=valor;
		ptr->siguiente->siguiente=0;
	}else{
		this->cabecera=new Celda();
		this->cabecera->datos=valor;
		this->cabecera->siguiente=0;
	}
}

string Lista::getCelda(int pos) const{

	Celda *ptr=cabecera;
	int cont=0;
	string cadena;
	bool salir=false;
	if(cont==pos)
		cadena=ptr->datos;
	else if(ptr != 0){
		while(ptr->siguiente !=0 && !salir){
			cont++;
			ptr=ptr->siguiente;

			if(cont == pos)
				salir=true;
		}
		if(salir){
			cadena=ptr->datos;
		}
		
	}
	return cadena;
}

int Lista::longitud() const{
	Celda *ptr=cabecera;
	int cont=0;
	
	while(ptr->siguiente != 0){
		ptr=ptr->siguiente;
		cont++;
	}
	cont++;

	return cont;
}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion 
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura 
 * 
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda 
 * en la lista. La función debe asegurarse de que la estructura sigue un patron 
 * determinado, y se ha de crear la lista con el numero de elementos que contenga. 
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
		}
		fin.close();
	}
	return true;
}

