/*
	Nombre: Luis Alberto Pérez Chapa
	ID: A01282564
	
	Proy F. Railroad
*/

#include <iostream>
using namespace std;

bool order(int car1, int car2, int tren1[], int tren2[], int arr[]){

    bool mat[car1 + 1][car2 + 1];
    mat[0][0] = true;

   // llenar primer columna
    for(int i = 1; i <= car1; i++){
        if(mat[i-1][0] != true){
            mat[i][0] = false;
        } 
        else{
            if(arr[i] == tren1[i]){
                mat[i][0] = true;
            } 
            else{
                mat[i][0] = false;
            }
        }
    }

    // llenar primer fila
    for(int i = 1; i <= car2; i++){
        if(mat[0][i-1] != true){
            mat[0][i] = false;
        } 
        else{
            if(arr[i] == tren2[i]){
                mat[0][i] = true;
            } 
            else{
                mat[0][i] = false;
            }
        }
    }

    // llenar toda la matriz
    for(int i = 1; i <= car1; i++){
        for (int j = 1; j <= car2; j++){
            if(mat[i-1][j] && (arr[i+j] == tren1[i])){ 
                    mat[i][j] = true;
            } 
            else if(mat[i][j-1] && (arr[i+j] == tren2[j])){
                mat[i][j] = true;
            } 
            else{
                mat[i][j] = false;
            }
        }
    }
    
    return mat[car1][car2];
}

int main() {

    // car1 = cantidad de vagones del tren1
    // car2 = cantidad de vagones del tren2
    int car1, car2, aux;
    cin >> car1 >> car2;

    while(car1 != 0 && car2 != 0) {

        // valores del tren1 y tren2
        // valores del resultado final a comprobar
        int tren1[car1];
        int tren2[car2];
        int number[car1+car2];
        
        // recibir valores del tren 1
        for(int i = 1; i <= car1; i++){
            cin >> tren1[i];
        }
        
        // recibir valores tren 2
        for(int i = 1; i<=car2; i++){
            cin >> tren2[i];
        }

        // recibir valores finales
        for(int i = 1; i <= (car1 + car2); i++) {
            cin >> number[i];
        }

        // mandar función order e imprimir resultados
        if (order(car1, car2, tren1, tren2, number) == true){
            cout << "possible" << endl;
        }
        else{
            cout << "not possible" << endl;
        }
        
        // recibir proximos valores (si son 0 0, se termina el ciclo)
        cin >> car1 >> car2;
    }

    // end program
    return 0;
}