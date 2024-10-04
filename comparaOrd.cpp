#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generarArregloAleatorio(int arreglo[], int n){
	for (int i = 0; i < n; i++){
		arreglo[i] = rand() % 100 + 1;
	}
}

int main(){
	srand(time(NULL));
	
	int n;
	cout << "Ingrese la cantidad de elementos de su arreglo: ", cin >> n;
	
	int arreglo[n];
	
	generarArregloAleatorio(arreglo, n);
	
	return 0;
}