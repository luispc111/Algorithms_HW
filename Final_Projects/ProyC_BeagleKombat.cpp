/*
	Nombre: Luis Alberto Pérez Chapa
	ID: A01282564
	
	Proy C. BeagleKombat
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int longitud, top, auxVal;
    cin >> longitud >> top;
    vector<int> values;

    for(int i = 0; i < longitud; i++){
        cin >> auxVal;
        values.insert(values.end(), auxVal);
    }

    string Button;
    cin >> Button;

    char cBack = Button[0];
    int max = values[0], counter = 0;

    priority_queue<int, vector<int>, greater<int> > pqueue;
    pqueue.push(values[0]);

    for (int i = 1; i < longitud; i++){
        
        //pqueue.push(values[i]);

        // si el botón es diferente
        if(Button[i] != cBack){
            max += values[i];
            cBack = Button[i];
            counter = 0;
            while(!pqueue.empty()){
                pqueue.pop();
            }
            pqueue.push(values[i]);
        }

        // si es el mismo que el anterior...
        else{
            pqueue.push(values[i]);
            counter++;
            // si no me he pasado el tope
            if(counter < top){
                max += values[i];
            }
            // si si me pasé el tope
            else{
                max -= pqueue.top();
                pqueue.pop();
                max += values[i];
            }
        }
    }

    cout << max << endl;
	return 0;
}
