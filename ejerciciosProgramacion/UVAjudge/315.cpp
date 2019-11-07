#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int numNodos;
vector<vector<int>> adj;

int hora;
vector<int> horaVertice, alcanzable;
vector<bool> solve;
int hijosRaiz;

void dfs(int u,int uParent) {
    horaVertice[u] = alcanzable[u] = hora; hora++;
    for(int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if(v == uParent) continue;
        if(horaVertice[v] == 0) {
            if(uParent == 0) 
                hijosRaiz++;
            dfs(v, u);
            if(alcanzable[v] >= horaVertice[u])
                if(uParent != 0) // u es punto de articulacion.
                    solve[u] = true;

            alcanzable[u] = min(alcanzable[u], alcanzable[v]);
        }    
        else
            alcanzable[u] = min(alcanzable[u], horaVertice[v]);
    }
}

int main() {
    string str;
    int nodo, num;
    cin >> numNodos;
    while(numNodos != 0){
        cin.ignore();
        adj = vector<vector<int>>(numNodos + 1);
        int a = 0;
        while(a < numNodos){
            getline(cin,str);
            if(str == "0")
                break;
            istringstream iss(str);
            iss >> nodo;
            while(iss >> num){
                adj[nodo].push_back(num);
                adj[num].push_back(nodo);
            }
            a++;
        }
        hora = 1;
        horaVertice = vector<int>(numNodos + 1,0);
        alcanzable = vector<int>(numNodos + 1,-1);
        solve = vector<bool>(numNodos + 1, false);
        for(int i = 1; i <= numNodos; ++i)
            if(!horaVertice[i]) {
                hijosRaiz = 0;
                dfs(i,0);
                if(hijosRaiz > 1 )
                   solve[i] = true;
            }
        
        cout << count(solve.begin(),solve.end(),true) << '\n';

        cin >> numNodos;
    }
    return 0;
}