/**
@file 
@author Bryan Moreno Picam�n
@date 16 de febrero de 2015, 19:33
@brief Funciones de manejo de bytes

*/

#ifndef _byte_H_
#define	_byte_H_

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef unsigned char byte; ///< Un @c byte contiene el estado de 8 bits

/**
@brief enciende el bit @p pos del @c byte @p b 
@param b 	el @c byte cuyo bit se quiere activar
@param pos 	el bit dentro de @p b que se quiere activar (0 m�s a la derecha)
*/
void on(byte &b, int pos);

/**
@brief apaga el bit @p pos del  @c byte @p b  
@param b 	el @c byte cuyo bit se quiere desactivar
@param pos 	el bit dentro de @p b que se quiere desactivar (0 m�s a la derecha)
*/
void off(byte &b, int pos);

/**
@brief devuelve el estado del bit (encendido = true, apagado = false) en la posici�n @p pos 
@param b 	el @c byte que se quiere consultar
@param pos 	el bit dentro de @ b que se quiere consultar (0 m�s a la derecha)
@retval true 	si el bit en la posici�n @p pos est� encendido
@retval false	si el bit en la posici�n @p pos est� apagado
*/
bool getbit(byte b, int pos);

/**
@brief Muestra por la salida est�ndar una secuencia de 0s y 1s correspondiente  al estado de cada bit
@param b el @c byte que se quiere imprimir

Muestra por la salida est�ndar una secuencia de 0s y 1s correspondiente  al estado de cada bit del byte donde un cero representa que un bit est� apagado y un uno que el bit est� encendido. Se implementa utilizando la funci�n "get".

Por ejemplo, si en el @c byte @c b est�n encendidos los bits en posiciones 1 y 3 (0 m�s a la derecha), @c print(b); mostrar� @c 00001010

*/
void print(byte b);

/**
@brief enciende todos los bits
@param b el @c byte que se quiere encender completamente. 
*/
void encender(byte &b);

/**
@brief apaga todos los bits
@param b el @c byte que se quiere apagar completamente. 
*/
void apagar(byte &b);

/**
@brief enciende los bits seg�n la configuraci�n de @p v
@param b el @c byte sobre el que se quiere actuar 
@param v vector de 8 elementos que contiene la secuencia de bitS que se quieren asignar

Asigna a @p b la configuraci�n de bits contenida en @p v. @p v es un vector de 8 booleanos donde @c true significa encendido y @c false significa apagado.
*/
void asignar(byte &b, const bool v[]);

/**
@brief recupera la configuraci�n de todos los bit
@param b el @c byte que se quiere consultar
@param v vector de 8 elementos que contendr� el estado de cada uno de los bits de @ b

Vuelca en @p v la configuraci�n de bits contenida en @p b. @c true significa encendido y @c false significa apagado. El tama�o de @p v debe ser 8.
*/
void volcar(byte b, bool v[]);

/**
@brief devuelve las posiciones de los bits encendidos
@param b el @c byte que se quiere consultar
@param posic vector de enteros (valores entre 0 a 7) que indican la posici�n de los bits de @p b que est�n encendidos
@param cuantos n�mero de bits encendidos en @p b (n�mero de elementos usados en el vector @p posic)
*/
void encendidos(byte b, int posic[], int &cuantos);

/**

@brief devuelve un string de los bits encendidos
@param b el @c byte que se quiere consultar
@return string con 0's y 1's de los bits consultados de b
*/
string byteToString(byte b);

#endif	

