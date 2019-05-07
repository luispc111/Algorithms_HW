/*
	Nombre: Luis Alberto Pérez Chapa
	ID: A01282564
	
	Proy H. Sparko Birthday II
*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int getCP(vector<vector<int> > path, vector<int> camino){

    int suma = 0;
    vector<bool> taken(path.size());
    
    // por cuales nodos heos pasado
    for(int i = 1; i < camino.size(); i++){
        taken[camino[i]] = true;
        suma += path[camino[i]][camino[i-1]];
    }
    
    // si ya no hay camino
    if(camino.size() == path.size()){
        return suma + path[camino.back()][0];
    } 

    // revisar conexión mínima
    int min = INT_MAX;
    for(int j = 1; j < path.size(); j++){
        if(!taken[j] && path[camino.back()][j] < min){
            min = path[camino.back()][j];
        }
    }
    
    // se encontró ninguno
    if(min != INT_MAX){
        suma += min;
    } 
    else{
        return INT_MAX;
    }

    // checar todos los demás
    for(int i = 1; i < path.size(); i++){
        if(taken[i] == true){
            continue;
        } 
        min = INT_MAX;

        for(int j = 0; j < path.size(); j++){
            if(!taken[j] && path[i][j] < min){
                min = path[i][j];
            }
        }

        if(min != INT_MAX){
            suma += min;
        } 
        else{
            suma = INT_MAX;
            break;
        }    
    }
    return suma;
}

int travel(vector<vector<int> > path,
    priority_queue<pair<int,vector<int> > , vector<pair<int,vector<int> > >, greater<pair<int,vector<int> > > > nodos){
    
    //se busca el costro mínimo
    // esta variable se regresará al final
    int costoMin = INT_MAX;
    
    // mientras existan nodos
    while(!nodos.empty()){

        pair<int,vector<int> > nodo = nodos.top();
        nodos.pop();

        if(nodo.first > costoMin){
            continue;
        }
        
        // nodos tocados
        vector<bool> taken(path.size());
        for(int i = 1; i < nodo.second.size(); i++){
            taken[nodo.second[i]] = true;
        }

        // camino
        if(nodo.second.size() == path.size()){
            int tot = nodo.first;
            if(tot < costoMin){
                costoMin = tot;    
            } 
            continue;
        }

        for(int i = 1; i < path.size(); i++){
            if(!taken[i] && path[nodo.second.back()][i] != INT_MAX){
                vector<int> newpath(nodo.second);
                newpath.push_back(i);
                int CP = getCP(path,newpath);
                if(CP != INT_MAX){
                   nodos.push(make_pair(CP, newpath));
                } 
            }
        }
    }

    // return value
    return costoMin;
}

int main(){

    // n     = doghouses
    // roads = roads
    int n, roads;
    cin >> n >> roads;
    
    // matríz de adyacencias, n x n
    vector< vector<int> > path(n, vector<int>(n));
    
    // llenar cada posición de la matriz path con INT_MAX
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            path[i][j] = path[j][i] = INT_MAX;
        }
    }
    
    // sale  = nodo partida
    // llega = nodo destino
    // dis   = distancia entre nodos
    char sale, llega;
    int dis;

    // pongo todos mis arcos en path
    for(int i = 0; i < roads; i++){
        
        cin >> sale >> llega >> dis;

        // resto el caracter menos 'A' para obtener su respectivo valor (A = 0, B = 1,...)
        path[(int)sale-'A'][(int)llega-'A'] = dis;
        path[(int)llega-'A'][(int)sale-'A'] = dis;
    }

    // vector con el camino de los nodos
    vector<int> camino;
    camino.push_back(0);
    
    // queue priorizada de nodos
    priority_queue<pair<int,vector<int> > , vector<pair<int,vector<int> > >, greater<pair<int,vector<int> > > > nodos;
    
    // Calculamos costo e insertamos a nodos
    int costPerf = 0;
    int min;
    for(int i = 0; i < path.size(); i++){
        min = INT_MAX;
        for(int j = 0; j < path.size(); j++){
            if(path[i][j] < min){
                min = path[i][j];
            }
        }
        costPerf += min;
    }
    nodos.push(make_pair(costPerf,camino));

    // answer contendrá el mejor camino
    // si no encontró, tendrá INT_MAX
    int answer = travel(path,nodos);

    // si no se encontró un camino posible
    if(answer == INT_MAX){
        cout << "INF" << endl;
    } 
    // si si se encontró camino
    else{
        cout << answer << endl;
    }
    return 0;
    // AAAAAAAA
}