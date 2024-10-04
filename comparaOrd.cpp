#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

const int MAXIMONUMERO = 10000;

void reduce(int arreglo[], int inicio, int final){
	int cen, pos, aux;
	int izq = inicio;
	int der = final;
	pos = izq;
	cen = 1;
	while(cen == 1){
		cen = 0;
		while((arreglo[pos] <= arreglo[der]) && (pos != der)){
			der--;
		}
		if (pos != der){
			aux = arreglo[pos];
			arreglo[pos]= arreglo[der];
			arreglo[der] = aux;
			pos = der;
			
			while((arreglo[pos] >= arreglo[izq]) && (pos != izq)){
				izq++;
			}
			if (pos != izq){
				aux = arreglo[pos];
				arreglo[pos] = arreglo[izq];
				arreglo[izq] = aux;
				pos = izq;
				cen = 1;
			}
		}
		if (pos-1 > inicio){
			reduce(arreglo, inicio, pos-1);
		}
		if (pos+1 < final){
			reduce(arreglo, pos+1, final);
		}
	}
}

void quickSort(int arreglo[], int n){
	reduce(arreglo, 0, n-1);
}

void insercionDirecta(int arreglo[],int n){
	int aux, k;
	for(int i = 1; i < n; i++){
		aux = arreglo[i];
		k = i-1;
		while(k>=0 && aux < arreglo[k]){
			arreglo[k+1] = arreglo[k];
			k--;
		}
		arreglo[k+1]=aux;
	} 
}

void generarArregloAleatorio(int arreglo1[], int arreglo2[], int n){
	for (int i = 0; i < n; i++){
		arreglo1[i] = arreglo2[i] = rand() % MAXIMONUMERO + 1;
	}
}

void mostrarArreglo(int arreglo[], int n){
	for (int i = 0; i < n; i++){
		cout << arreglo[i] << " ";
	}
}

void ejecutarInsercionDirecta(int arreglo1[], int n){
	auto inicio = chrono::high_resolution_clock::now();
	insercionDirecta(arreglo1, n);
	auto final = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = final - inicio;
	cout << "Tiempo de ejecucion del algoritmo: " << duration.count() << endl;
	//mostrarArreglo(arreglo1, n);
}

void ejecutarQuickSort(int arreglo2[], int n){
	auto inicio = chrono::high_resolution_clock::now();
	quickSort(arreglo2, n);
	auto final = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = final - inicio;
	cout << "Tiempo de ejecucion del algoritmo: " << duration.count() << endl;
	//mostrarArreglo(arreglo2, n);
}

void menu(int arreglo1[], int arreglo2[], int n){
	int option;
	do {
		cout << "\nOpciones del programa" << endl;
		cout << "1. Ordenar por algoritmo de insercion directa" << endl;
		cout << "2. Ordenar por algoritmo QuickSort" << endl;
		cout << "3. Generar nuevamente el arreglo aleatoriamente" << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion: ", cin >> option;
		cout << endl;
		switch(option){
			case 1:
				ejecutarInsercionDirecta(arreglo1, n);
				break;
			case 2:
				ejecutarQuickSort(arreglo2, n);
				break;
			case 3:
				generarArregloAleatorio(arreglo1, arreglo2, n);
				break;
			case 0:
				cout << "Saliendo..." << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
		} 	
	} while(option != 0);

}

int main(){
	srand(time(NULL));
	
	int n;
	cout << "Ingrese la cantidad de elementos de su arreglo: ", cin >> n;
	
	int arreglo1[n];
	int arreglo2[n];
	
	generarArregloAleatorio(arreglo1, arreglo2, n);
	
	menu(arreglo1, arreglo2, n);
	
	return 0;
}