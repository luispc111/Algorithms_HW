/*
	Nombre: Luis Alberto P�rez Chapa
	ID: A01282564
	
	Proy A. Median
*/

#include <iostream>
#include <iomanip> /* para el setprecision(2) del cout en la linea 77 */
using namespace std;

double findMedian(double uno[], double dos[], int n) {

    // si el size de mis arreglos es 1, regresa	el promedio de ambos
	if (n == 1){
        return (uno[0]+dos[0])/2;
    } 
	
    // si el size es 2, realiza estas sumas y regresa el valor
	if (n == 2){
        double sum = 0;
        sum += (uno[0] > dos[0]) ? uno[0] : dos[0];
        sum += (uno[1] > dos[1]) ? dos[1] : uno[1];
        return sum/2;
    } 

    // valores de las tentativas medianas
	int med1, med2;
    //                  si es par...              si es impar...
    med1 = (n%2 == 0) ? (uno[n/2] + uno[n/2-1])/2 : uno[n/2];
    med2 = (n%2 == 0) ? (dos[n/2] + dos[n/2-1])/2 : dos[n/2];	
	
    // si el valor de la izq es menor al de la derecha
	if (med1 < med2) {
        //                  si n es impar...
		return (! n%2) ?    findMedian(uno + n/2-1, dos, n-(n/2)+1) : 
        //                  si es par...                    
                            findMedian(uno + n/2  , dos, n-(n/2)  );
	}
	
    // si n es impar...
	if(! n%2){
		return findMedian(dos+n/2-1, uno, n-(n/2)+1);
	}
    // si n es par...
	else{
		return findMedian(dos+n/2, uno, n-(n/2));
	}
}

int main() {

    // cases = cantidad de casos
    // n     = length de los arreglos por recibir
	int cases, n;
    cin >> cases;

    // para cada caso
	for (int i = 0; i < cases; i++){
		
        // crear arreglos
        cin >> n;
		double uno[n];
		double dos[n];

        // recibir valores arreglo uno
		for(int j = 0; j < n; j++){
			cin >> uno[j];
        }
		
        // recibir valores arreglo dos
        for(int j = 0; j < n; j++){
			cin >> dos[j];
		}
        
		// print results con 2 decimales
		cout << fixed <<
        "Median case " << (i+1) << ": " << setprecision(2) << 
		findMedian(uno, dos, n) << endl;
	}

    // end program
	return 0;
}
