/*
	Nombre: Luis Alberto Pérez Chapa
	ID: A01282564
	
	Proy D. BeagleBalls
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

  	int soldiers, balls, aux1, aux2, sum = 0;
	cin >> soldiers >> balls;
	
	vector<int> S;
	queue<int> B;
	
	// lleno un arreglo
	aux1 = soldiers;
	while (aux1 > 0){
		cin >> aux2;
		sum += aux2;
		S.push_back(sum);
		aux1--;
	}
	
	// lleno otro arreglo
	aux1 = balls;
	sum = 0;
	while (aux1 > 0){
		cin >> aux2;
		B.push(aux2);
		aux1--;
	}
	
	sum = 0;
	int pos = 0, start = 0, end = soldiers-1;
	bool check = false;
	
	// evaluar cada bola
	while(!B.empty()){
		 
         sum += B.front();

		// si tumba a TODOS los soldados
		if(sum >= S[soldiers-1]){
			cout << soldiers << endl;
			sum = 0;
		}

		// si no alcanzó a tumbar NINGÚN soldado
		else if (sum < S[0]){
			cout << soldiers << endl;
		}
 
		else{	
			pos = (soldiers) / 2;
			
			// encontrar las posición 
			// al final, pos deberá tener la ultima posición que SI se alcanzó a tumbar
			while(!check){
				
				if(S[pos] <= sum && S[pos+1] > sum){
					check = true;
				}
				else{
					if(S[pos] > sum){
						end = pos;
						pos -= ((end-start)/2 > 0) ? (end-start)/2 : 1;
					}
					else{
						start = pos;
						pos += ((end-start)/2 > 0) ? (end-start)/2 : 1;					
					}
				}
			}

			start = 0;
			end = soldiers-1;
	
			cout << soldiers-pos-1 << endl;		
		}
		
		check = false;
		
		// retirar una bola
		B.pop();
	}
    //cout << endl;
	
	return 0;
}
