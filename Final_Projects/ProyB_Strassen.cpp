/*
	Nombre: Luis Alberto Pérez Chapa
	ID: A01282564
	
	Proy B. Strassen
*/

#include <iostream>
using namespace std;

#define N 80
int strass = 0;

int trad(int n, int matA[N][N], int matB[N][N]){ 
	
	int matC[n][n], multi = 0;

	// calcular cantidad de multiplicaciones
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) { 
			matC[i][j] = 0; 
			for (int k = 0; k < n; k++) { 
				matC[i][j] += matA[i][k] * matB[k][j]; 
				multi++;
			} 
		} 
	}

	// return value
	return multi; 
} 

void sum(int n, int matA[N][N], int matB[N][N], int matC[N][N]) {
	
	// recorrer matA y matB
	// sumar en matC, la suma de los valores en matA y matB en la misma posición
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matC[i][j] = (matA[i][j] + matB[i][j]);
		}
	}
}

void sub(int n, int matA[N][N], int matB[N][N], int matC[N][N]) {

	// almacenar en matC la resta de matA - matB
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matC[i][j] = matA[i][j] - matB[i][j];
		}
	}
}

void strassen(int n, int matA[N][N], int matB[N][N], int matC[N][N]) { 
	
	// añadir una multiplicación
	strass++;

	// cuando termine la recursividad
	if (n == 1) {
		matC[0][0] = matA[0][0] * matB[0][0];
		return;
	} 
	
	// To keep devidin
	int median = n/2;

	// de matriz A
	int matA00[N][N], matA01[N][N];
	int matA10[N][N], matA11[N][N];

	// de matriz B
	int matB00[N][N], matB01[N][N];
	int matB10[N][N], matB11[N][N];
	    
	// de matriz C
	int matC00[N][N], matC01[N][N]; 
	int matC10[N][N], matC11[N][N];
	    
	// matrices auxs
	int matAux1[N][N], matAux2[N][N]; 
	int matAux3[N][N], matAux4[N][N]; 
	int matAux5[N][N], matAux6[N][N]; 
	int matAux7[N][N];
	    
	// results matrices
	int resMatA[N][N], resMatB[N][N];

	for (int i = 0; i < median; i++) {
		for (int j = 0; j < median; j++) {
			
			matA00[i][j] = matA[i][j];
			matB00[i][j] = matB[i][j];

			matA01[i][j] = matA[i][j+median];
			matB01[i][j] = matB[i][j+median];

			matA10[i][j] = matA[i+median][j];
			matB10[i][j] = matB[i+median][j];

			matA11[i][j] = matA[i+median][j+median];
			matB11[i][j] = matB[i+median][j+median];
		}
	}

	sum(median, matA00, matA11, resMatA);
	sum(median, matB00, matB11, resMatB);
	strassen(median, resMatA, resMatB, matAux1);

	sum(median, matA10, matA11, resMatA);
	strassen(median, resMatA, matB00, matAux2);

	sub(median, matB01, matB11, resMatB);
	sub(median, matB01, matB11, resMatB);
	strassen(median, matA00, resMatB, matAux3);

	sub(median, matB10, matB00, resMatB);
	strassen(median, matA11, resMatB, matAux4);
	sum(median, matA00, matA01, resMatA);
	strassen(median, resMatA, matB11, matAux5);

	sub(median, matA10, matA00, resMatA);
	sum(median, matB00, matB01, resMatB);
	strassen(median, resMatA, resMatB, matAux6);

	sub(median, matA01, matA11, resMatA);
	sum(median, matB10, matB11, resMatB);
	strassen(median, resMatA, resMatB, matAux7);

	sum(median, matAux3, matAux5, matC01);
	sum(median, matAux2, matAux4, matC10);

	sum(median, matAux1, matAux4, resMatA);
	sum(median, resMatA, matAux7, resMatB);
	sub(median, resMatB, matAux5, matC00);

	sum(median, matAux1, matAux3, resMatA);
	sum(median, resMatA, matAux6, resMatB);
	sub(median, resMatB, matAux2, matC11);

	for (int i = 0; i < median; i++) {
		for (int j = 0; j < median; j++) {
			matC[i][j] = matC00[i][j];
			matC[i][j+median] = matC01[i][j];
			matC[i+median][j] = matC10[i][j];
			matC[i+median][j+median] = matC11[i][j];
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	int matA[N][N];
	int matB[N][N];
	int matC[N][N];

	// matriz A
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matA[i][j];
		}
	}

	// matriz B
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matB[i][j];
		}
	}

	strassen(n, matA, matB, matC);

	// imprimir resultados
	cout << "Traditional Scalar Multiplications: " << trad(n, matA, matB) << endl;
	cout << "Strassen Scalar Multiplications: " << (strass-1) << endl;
	
	// imprimir matriz
	cout <<  "Strassen Result Matrix:" << endl;
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << matC[i][j] << " ";
		}
		cout << endl;
	}
	
	// End program
	return 0;
}
