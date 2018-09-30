/**
@file 
@brief Clase imagen blanco y negro.
*/

#ifndef _IMAGEN_H_
#define _IMAGEN_H_
#include "pgm.h"
#include "byte.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <string>
#include "lista.h"

typedef unsigned char byte; ///< byte = 8bits almacenado en un unsigned char
using namespace std;

/**
@brief Una imagen en blanco y negro. Cada píxel es un byte
*/
class Imagen{
private:
   static const int MAXPIXELS = 1000000; ///< número máximo de píxeles que podemos almacenar
   byte** datos;///< datos de la imagen
   int nfilas; 			///< número de filas de la imagen
   int ncolumnas;		///< número de columnas de la imagen
public:
/**
@brief Destructor de la clase Imagen
*/
   ~Imagen();

/**
@brief Construye una imagen vacía (0 filas, 0 columnas)
@param Imagen que se va a copiar a la imagen actual
*/
   Imagen(); 
   
/**
@brief Construye una imagen como copia de la pasada por parametro
@param Imagen que se va a copiar a la imagen actual
*/
   Imagen(const Imagen &img); 

/**
@brief Operador de asignacion para la clase Imagen
@param Imagen que se va a asignar a la imagen actual
@retval imagen resultado
*/
   Imagen operator= (const Imagen &img);


/**
@brief Dado un numero, k, extraiga el plano de bits k-ésimo de la imagen actual y lo devuelve como una nueva imagen
@param posicion k
@retval imagen resultado
*/
   Imagen operator+(const Imagen &img);
   
/**
@brief Construye una imagen de tamaño @a filas x @a columnas y pone todos 
sus elementos a 0.
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen


*/
   Imagen(int filas, int columnas);
   
   
/**
@brief Crea una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos 
sus elementos a 0.
*/
   void crear(int filas, int columnas);
   
   
/**
@brief Devuelve el número de filas de las imagen
@return el número de filas de la imagen
*/
   int filas()const; 

   
/**
@brief Devuelve el número de columnas de las imagen
@return el número de columnas de la imagen
*/
   int columnas()const; 
   

/**
@brief Asigna el valor @a v a la posición (@a x,@a y) de la imagen
@param y 	fila de la imagen
@param x 	columna de la imagen 
@param v 	valor a asignar

Asigna el valor @a v a la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x 
del vector.    
*/
   void set(int y, int x, byte v); 
   
   
/**
@brief Devuelve el valor de la posición (@a x,@a y) de la imagen
@param y	 fila de la imagen
@param x	 columna de la imagen 
@return el valor de la posición (@a x,@a y) de la imagen

Devuelve el valor de la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x 
del vector.    
*/
   byte get(int y, int x)const; 
   
   
/**
@brief Asigna el valor @a v a la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
@param v 	valor a asignar

Asigna el valor @a v a la posición @a i de la imagen considerada como vector. La posición @a i 
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la 
fila y @c x representa la columna.    
*/
   void setPos(int i, byte v); 
   
 
/**
@brief Devuelve el valor de la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector

Devuelve el valor de la posición @a i de la imagen considerada como vector. La posición @a i 
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la 
fila y @c x representa la columna.    
*/
   byte getPos(int i);

   
/**
@brief Carga una imagen desde un fichero 
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la lectura
@retval false 	si se ha producido algún error en la lectura

Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. La función debe asegurarse de que la imagen es de un tipo de imagen conocido y de que su tamaño es menor del tamaño máximo permitido (@c MAXDATOS).
*/
   bool leerImagen(const char nombreFichero[]);
   

/**
@brief Guarda una imagen desde un fichero 
@param nombreFichero nombre del fichero que contiene la imagen
@param esBinario toma el valor @c true si el fichero se escribe en formato binario o @c false en caso contrario.
@retval true 	si ha tenido éxito en la escritura
@retval false 	si se ha producido algún error en la escritura
*/
   bool escribirImagen(const char nombreFichero[], bool esBinario)const; 

/**
@brief Dado un numero, k, extraiga el plano de bits k-ésimo de la imagen actual y lo devuelve como una nueva imagen
@param posicion k
@retval imagen resultado
*/
   Imagen plano(int k);

/**
@brief Convierte una imagen a un conjunto de caracteres ASCII
@param grises vector con los caracteres ASCII que se usaran para representar la imagen
@param arteASCII vector de caracteres de la imagen resultado
@param maxlong longitud maxima del vector arteASCII
@retval true 	si ha tenido éxito en la conversion
@retval false 	si se ha producido algún error en la conversion
*/
   bool aArteASCII(const char grises[], char arteASCII[], int maxlong);


   bool listaAArteASCII(const Lista &celdas);

/**
@brief Funcion auxiliar para crear asignar a la @a img2 la @a img1
@param img1 imagen constante que contiene la imagen que se copiara en @a img2
@param img2 imagen resultante de copiar los datos de @a img1
*/
   void copiarImagen(const Imagen &img1, Imagen &img2);

/**
@brief Libera la memoria dinamica
*/
   void destruir();

};
#endif
