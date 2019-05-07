/*
	Nombre: Luis Alberto Pérez Chapa
	ID: A01282564
	
	Proy E. How many trees?
*/

#include <iostream>
#include <vector>
using namespace std;

unsigned long int counting(int nodes){

       vector <unsigned long int> T(nodes + 1) ;
        
        // inicializar valores
        T[0] = 1;
        T[1] = 1;
        
        for(int i = 2; i <= nodes; i++){
            for(int j = 0; j < i; j++){
                T[i] += T[j] * T[i-j-1];
            }
        }

        return T[nodes];
    }

int main(){
    
    // cantidad de nodos
    int nodes;
    cin >> nodes;

    cout << counting(nodes) << " BTrees" << endl;
    return 0;
}