#include <iostream>
#include <string.h>

const int nElementos = 16; //numero de elementos totales de la lista del enunciado

using namespace std;

void llenarLista(int lista[nElementos]); //llena manualmente la lista por defecto del enunciado
void imprimirLista(int lista[nElementos], char titulo[50]); //imprime la lista
int busquedaBinaria(int lista[nElementos], int registro); //función que implementa el algoritmo de busqueda binaria y retorna la posisión en caso de existir el registro

int main(int argc, char** argv) {
	int lista[nElementos], posicion, precio; //define la lista por defecto del enunciado y la variable de posicion del registro a buscar
	char titulo[50]; //variable para imprimir el titulo de la lista
	
	llenarLista(lista); // se llama al metodo que llena la lista de forma manual	
	strcpy(titulo, "Lista de entrada: "); // asigna el nombre de lista a mostrar: lista de entrada
	imprimirLista(lista, titulo); //imprime la lista inicial
	
	precio = 29; // el precio a buscar en el enunciado es 29
	posicion = busquedaBinaria(lista, precio); // se guarda la posicion que retorna el metodo de busqueda binaria
	
	if(posicion == -1){ // si la posición retornada es -1, quiere decir que el resgistro no fue encontrado
		cout << endl << "** El precio de " << precio << "$ del tipo de rosa a buscar no se encuenta en la lista." << endl;
	}else{ // si la posicion retornada es diferente de -1, indica que si se encontró y se imprime la posición del registro
		cout << endl << "** El precio de " << precio << "$ del tipo de rosa a buscar se encuentra en la lista de entrada, en la posicion: " << posicion << endl;
	}
	
	cout << endl;
	system("pause");
}

void llenarLista(int lista[nElementos]){ //Función que llena la lista de forma manual, con los valores dados en el enunciado
	lista[0] = 17;
	lista[1] = 19;
	lista[2] = 21;
	lista[3] = 22;
	lista[4] = 24;
	lista[5] = 26;
	lista[6] = 29;
	lista[7] = 31;
	lista[8] = 32;
	lista[9] = 33;
	lista[10] = 35;
	lista[11] = 36;
	lista[12] = 37;
	lista[13] = 39;
	lista[14] = 40;
	lista[15] = 45;
}


void imprimirLista(int lista[nElementos], char titulo[50]){ //Imprime el titulo y los valores de la lista
	cout << titulo << endl << "\t";
	for(int i = 0; i < nElementos; i ++){ //Recorre todos los elementos de la lista
		if(i == nElementos - 1){ // si es el ultimo elemento no imprime la , luego del valor
			cout << lista[i];
		}else{ // si no es el ultimo elemento imprime la , luego del valor correspondiente en la lista
			cout << lista[i] << ", ";
		}
	}
	cout << endl << "\t";
	for(int i = 0; i < nElementos; i ++){ //Imprime las posiciones de la lista, para una mejor visualización del resultado final
		if(i < 10){
			cout << " " << i << "| ";
		}else{
			cout << i << "| ";
		}
	}
	
	cout << "-> Posiciones de la lista" << endl;
}

int busquedaBinaria(int lista[nElementos], int registro){ //Funcion que aplica la busqueda binaria
/*
Para aplicar este tipo de busqueda, es necesario que la lista ingresada se encuente ordenada de forma ascendente, tal y como está la lista de entrada del enunciado.
La busqueda binaria consiste en dividir el vector o lista en dos, obtiendo así un punto medio que será el que compararemos con el resgistro o dato a buscar,
a su vez, definimos dos limites, el limite inferior o izquierdo y el limite superior o derecho, inicialmente ambos se encuentran en los extremos de la lista,
si el la lista en el punto medio no coincide con el dato a buscar, se mueven los limites de la siguiente manera:
si el dato es menor al valor de la lista en el punto medio, se desplaza el limite derecho en una posición, 
si el dato es mayor al valor de la lista en el punto medio, se desplaza el limite izquierto en una posición, 
así hasta o bien conseguir el dato o descartar su existencia.
*/
	int puntoMedio, limiteIzquierdo = 0, limiteDerecho = nElementos - 1; //declaramos e inicializamos los limites y punto medio
	bool encontrado = false; //bandera booleana que indicará si el dato fue encontrado o no
	
	if( registro >= lista[0] && registro <= lista[nElementos - 1]){ //como la lista está ordenada, el dato debe encontrarse dentro del rango del valor menor y el valor mayor de la lista, si no es asi, el dato no se encuentra dentro de la misma
		while(encontrado == false &&  limiteIzquierdo <= limiteDerecho){ //Mientras el dato no se haya encontrado y el limite izquierdo sea menor o igual al derecho (es decir, mientras hayan un rango de limites entre los cuales buscar)
			puntoMedio = (limiteIzquierdo + limiteDerecho)/2; //El punto medio será la mitad de ambos limites
			if(registro == lista[puntoMedio]){ //si el valor de la lista en el punto medio es igual al dato a buscar, se marca como encontrado
				encontrado = true;
			}else{ //si el valor de la lista en el punto medio no es igual al dato a buscar, se mueven los limites tomando en cuenta las instrucciones dadas
				if(registro < lista[puntoMedio]){ //si el dato a buscar es menor al valor de la lista en el punto medio, se desplaza el limite derecho en una posición
					limiteDerecho = puntoMedio - 1;
				}else{ //si el dato a buscar es mayor al valor de la lista en el punto medio, se desplaza el limite izquierto en una posición
					limiteIzquierdo = puntoMedio + 1;
				}
			}
		}
	}
	
	if(encontrado == true){ //si el dato fue encontrado, se retorna la posición en la cual se encuentra
		return puntoMedio;
	}else{ //si el dato no fue encontrado, se retorna -1, para indicar que no existe en la lista de entrada
		return -1;
	}
}
