//lee imagenes/gio.pgm y la convierte en ascii con los caracteres "@%#*+=-:. "
#include<iostream>
#include<imagen.h>

using namespace std;

int main(){
    char grises[] = "@#%xo;:,. ";
    //char grises[] = "#$:.";
    //char grises[] = "\"mQt]?’ ";
    //char grises[] = "@%#*+=-:. ";
    //char grises[] = "$B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+<>i!lI;:,\"^’‘. ";

    char arteASCII[4501]; // 4500 + el \0
    
    Imagen origen;

    // Leer la imagen gio.pgm
    if (!origen.leerImagen("imagenes/gio.pgm")){
	   cerr << "error leyendo imagenes/gio.pgm\n";
	   return 1;
    }
	
    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, 4500))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;  
	
    cout << "Ahora Forzamos que no quepa. Debe aparecer un mensaje de error\n";
    if(origen.aArteASCII(grises, arteASCII, 4199))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;
    
}
