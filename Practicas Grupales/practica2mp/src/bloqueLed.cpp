#include "bloqueLed.h"

void on(bloqueLed &b, int pos){
	bloqueLed mask = 1;
	mask <<=pos;
	b=(b|mask);
}

void off(bloqueLed &b, int pos){
	bloqueLed mask = 1 << pos;
	b=(b&~mask);
}

bool get(bloqueLed b, int pos){
	bloqueLed mask = 1 << pos;
	return(b&mask);
}

void print(bloqueLed b){
bloqueLed mask = 128;
	while (mask>0) {
	    printf("%d", (b & mask) > 0 );
	    mask >>= 1;
	}
printf("\n" );	
}

void encender(bloqueLed &b){
	b=255;
}

void apagar(bloqueLed &b){
	b=0;
}

void asignar(bloqueLed &b, const bool v[]){
	for(int i=0;i<8;i++)
		if(v[i])
			on(b,i);
		else
			off(b,i);
}

void volcar(bloqueLed b, bool v[]){
	for(int i=0;i<8;i++)
		v[i]=(bool)get(b,i);
}


void encendidos(bloqueLed b, int posic[], int &cuantos){
	int j=0;
	for(int i=0;i<8;i++)
		if(get(b,i)){
			posic[j]=i;
			j++;
		}
	cuantos=j;
}

string bloqueLedToString(bloqueLed b){
	std::string s;
	for(int i=0;i<8;i++)
		s=s+(char)get(b,i);
}
