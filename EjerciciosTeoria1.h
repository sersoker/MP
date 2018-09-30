/*******************************/
/************EJERCICIO3*********/
/*******************************/
//Funcion que elimine los elementos repetidos guard´andolos en un nuevo array
//Nombre: eliminaRepetidosAuxiliar
//Argumentos: array inicial y su tamaño (no modificables), array donde almacenar resultado y su tamaño

void eliminaRepetidosAuxiliar(const int array[], int tamArray, int salida[],int &tamSalida){
	salida[0]=array[0];
	tamSalida=1;
	bool esta=false;
	
	for(int i=1,i<tamArray;i++){
		for(int j=0;j<tamSalida&&!esta;j++){
			if(array[i]==salida[j])
				esta=true;
		}
		
		if(!esta){
			salida[tamSalida]=array[i];
			tamSalida++;
		}
		esta=false;
	}
	
}


//Funcion que elimine los elementos repetidos sin usar array auxiliar
//Nombre: eliminaRepetidos
//Argumentos: array inicial y su tamaño.

void eliminaRepetidos(int array[], int &tamArray){

	for(int i=0,i<tamArray;i++){
		for(int j=i+1;j<tamArray-1;j++){
			if(array[i]==array[j]){
				eliminaElemento(array,tamArray,j);
				j--;
			}
		}
	}
	
}

//Funcion que elimine un elemento deun array desplazando el resto
//Nombre: eliminaElemento
//Argumentos: array del que borrar un elemento, su tamaño y la posicion del elemento.

void eliminaElemento(int array[],int &tamArray,int posicion){
	
	tamArray--;
	for(int i=posicion;posicion<tamArray;i++){
		array[i]=array[i+1];
	}

}

/*******************************/
/************EJERCICIO4*********/
/*******************************/
//Funcion que obtenga la mayor secuencia mon´otona creciente de un array de enteros, guard´andola en otro array 
//Nombre: obtenerSecuenciaCreciente
//Argumentos: array inicial y su tamaño (no modificables), array donde almacenar resultado y su tamaño

void obtenerSecuenciaCreciente(const int array[], int tamArray, int salida[],int &tamSalida){
	int longAct=1;
	int longMax=1;
	
	int posMax=0;
	int posAct=0;
	
	for(int i=1;i<tamArray;i++){
		if(array[i]>array[i-1]){
			longAct++;
		}
		else{
			if(longAct>longMax){
				longAct=longMax;	posAct=posMax;
				posAct=i;
			}
		}
	}
	
	tamSalida=0;
	for(int i=posMax;i<posMax+longMax;i++){
		salida[tamSalida]=array[i];
		tamSalida++		
	}
	
}





/*******************************/
/************EJERCICIO13*********/
/*******************************/
//Clase que rellene dos arrays con  la recurrencia :
	/* 
		a0 = b0 = 1
		an = bn−1
		bn = an−1 + 2bn−1
	*/
//Nombre: claseRecurrencia


class claseRecurrencia{
private:
	static const int TAM=10000;
	int vectorA[TAM];
	int vectorB[TAM];
	int totalUtilizados;


void rellenaRecurrencia(){
	vectorA[i]=vectorB[i]=1;
	for(int i=1;i<TAM;i++){
		vectorA[i]=vectorB[i-1];
		vectorB[i]=vectorA[i-1]+(2*vectorB[i-1]);
	}
	totalUtilizados=TAM;
}	

void imprimeRecurrencia(){
	for(int i=0;i<totalUtilizados;i++){
		cout << i << " "<< vectorA[i] << " "<< vectorB[i] << " "<< vectorA[i]/vectorB[i]<<endl;
	}
	
}	
	
	
};


