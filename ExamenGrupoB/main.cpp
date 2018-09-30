/**
@file main.cpp
@brief 
Universidad de Granada
Metodología de la Programación I
Examen de laboratorio 

Por favor, rellene las funciones que se indican
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Número de elementos que contiene @a v
*/
void imprimirVector(string *v, int n)  {
	cout << n << " elementos" << endl;
	for (int i=0; i<n; i++)
		cout << "["<<i<<"] = " << v[i] << endl;
}

/**
@brief Compara dos vectores y devuelve uno nuevo con la diferencia
@param v1 	Vector a comparar 1
@param n1 	Numero de elementos de @a v1
@param v2 	Vector a comparar 2
@param n2 	Numero de elementos de @a v2
@param vr 	Vector de resultado
@param nr	Número de elementos que contiene @a vr
*/
void operacionExamenDistintos(string *v1, int n1,string *v2, int n2,string *vr, int nr)  {
bool seguir=true;
int indiceSalida=0;

	for(int i=0;i<n2;i++){
		for(int j=0;j<n1&&seguir;j++){
			if(v2[i]==v1[j])
				seguir=false;
		}
		if(seguir){
			vr[indiceSalida]=v2[i];
			indiceSalida++;
		}
		else
			seguir=true;

	}

}

/**
@brief Compara dos vectores y devuelve uno nuevo con la interseccion
@param v1 	Vector a comparar 1
@param n1 	Numero de elementos de @a v1
@param v2 	Vector a comparar 2
@param n2 	Numero de elementos de @a v2
@param vr 	Vector de resultado
@param nr	Número de elementos que contiene @a vr
*/
void operacionExamenIguales(string *v1, int n1,string *v2, int n2,string *vr, int nr)  {
bool encontrado=false;
int indiceSalida=0;

	for(int i=0;i<n2;i++){
		for(int j=0;j<n1&&!encontrado;j++){
			if(v2[i]==v1[j])
				encontrado=true;
		}
		if(encontrado){
			vr[indiceSalida]=v2[i];
			indiceSalida++;
			encontrado=false;
		}
	}

}

int main()  {
	string *A=NULL, *B=NULL, *Resultado=NULL,*Resultado2=NULL;
	int elemA, elemB, elemResultado,elemResultado2;
	ifstream FichA, FichB;

	
	/// Examen: Leer fichero en vector A
		FichA.open("./mod5A.txt");
		if(FichA){
			FichA>>elemA;
			A=new string[elemA];
			for(int i=0;i<elemA;i++){
				FichA>>A[i];
			}
		}
		FichA.close();
		imprimirVector(A, elemA);

	/// Examen: Leer fichero en vector B
		FichB.open("./mod5B.txt");
		if(FichB){
			FichB>>elemB;
			B=new string[elemB];
			for(int i=0;i<elemB;i++){
				FichB>>B[i];
			}
		}
		FichB.close();
		imprimirVector(B, elemB);

	/// Examen: Calcular resultado distintos
		elemResultado=elemB-elemA;
		Resultado=new string[elemResultado];
		operacionExamenDistintos(A,elemA,B,elemB,Resultado,elemResultado);

	/// Examen: Mostrar resultado
		imprimirVector(Resultado, elemResultado);

	/// Examen: Calcular resultado iguales
		elemResultado2=elemA;
		Resultado2=new string[elemResultado2];
		operacionExamenIguales(A,elemA,B,elemB,Resultado2,elemResultado2);

	/// Examen: Mostrar resultado
		imprimirVector(Resultado2, elemResultado2);

	/// Examen: Terminación del programa
		delete [] A;
		delete [] B;
		delete [] Resultado;
		delete [] Resultado2;

	return 0;
}
 
