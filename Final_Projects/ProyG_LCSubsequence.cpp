/*
	Nombre: Luis Alberto Pérez Chapa
	ID: A01282564
	
	Proy G. Longest Common Subsequence
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    int cases;string one, two;
    cin >> cases;

    // por cada case
    for(int i = 0; i < cases; i++){
    
        cin >> one >> two;
        int mat[one.length()+1][two.length()+1];

        // Lleno la columna de 0s
        for(int x = 0; x <= one.length(); x++){
            mat[x][0] = 0;
        }

        // Lleno fila de 0s
        for(int x = 0; x <= two.length(); x++){
            mat[0][x] = 0;
        }

        // voy poniendo mis valores
        for(int j = 1; j <= one.length(); j++){
            for(int k = 1; k <= two.length(); k++){
                if(one[j-1] != two[k-1]){
                    mat[j][k] = (mat[j-1][k] >= mat[j][k-1]) ? mat[j-1][k] : mat[j][k-1];
                }
                else{
                    mat[j][k] = mat[j-1][k-1] + 1;
                }
            }
        }
        cout << "Case " << i+1 << ": " << mat[one.length()][two.length()] << endl;
    }
	return 0;
}
