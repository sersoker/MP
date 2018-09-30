#include "byte.h"

void on(byte &b, int pos){
	byte mask = 1;
	mask <<=pos;
	b=(b|mask);
}

void off(byte &b, int pos){
	byte mask = 1 << pos;
	b=(b&~mask);
}

bool getbit(byte b, int pos){
	byte mask = 1 << pos;
	return(b&mask);
}

void print(byte b){
byte mask = 128;
	while (mask>0) {
	    printf("%d", (b & mask) > 0 );
	    mask >>= 1;
	}
printf("\n" );	
}

void encender(byte &b){
	b=255;
}

void apagar(byte &b){
	b=0;
}

void asignar(byte &b, const bool v[]){
	for(int i=0;i<8;i++)
		if(v[i])
			on(b,i);
		else
			off(b,i);
}

void volcar(byte b, bool v[]){
	for(int i=0;i<8;i++)
		v[i]=(bool)getbit(b,i);
}


void encendidos(byte b, int posic[], int &cuantos){
	int j=0;
	for(int i=0;i<8;i++)
		if(getbit(b,i)){
			posic[j]=i;
			j++;
		}
	cuantos=j;
}

string byteToString(byte b){
	string s;
	for(int i=0;i<8;i++){
		if(getbit(b,i)){
			s+="1";
		}else{
			s+="0";
		}
	}
	return s;
}
