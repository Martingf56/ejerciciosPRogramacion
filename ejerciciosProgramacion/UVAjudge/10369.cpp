#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
// se usa union-find

using namespace std;

using arista = pair<double, pair<int,int>>; // < coste, extremos >
vector<arista> aristas;
int V, Sats;

// union-find
vector<int> C;
int numSets;

void init(int n) {
   C.assign(n, 0);
   for (int i = 0; i < n; ++i) C[i] = i;
   numSets = n;
}

int find(int a) {
   return (C[a] == a) ? a : C[a] = find(C[a]);
}

// find(a) != find(b)
void merge(int a, int b) {
   C[find(a)] = find(b);
   --numSets;
}

   // guardar las aristas en el vector
void KrusKal(){
   // Kruskal
   init(V);
   double coste = 0;
   for (auto ar : aristas) {
      if (numSets == Sats) 
         break;
      if (find(ar.second.first) != find(ar.second.second)) {
         merge(ar.second.first, ar.second.second);
         coste = ar.first;
      }
   }
   cout << fixed << setprecision(2) << coste << '\n';
}

int main(){
    int ncs,satelites,avanzadas;
    cin >> ncs;
    while(ncs--){
         cin >> satelites >> avanzadas;
         vector<pair<int,int>> avanz;
         for(int i = 0; i < avanzadas;i++){
               int x,y;
               cin >> x >> y;
               avanz.push_back({x ,y});
         }  
         aristas = vector<pair<double,pair<int,int>>>();
         double d;
         for(int i = 0; i < avanzadas; i++)
               for(int j = i + 1; j < avanzadas; j++){
                  d = sqrt(pow(avanz[i].first - avanz[j].first,2) + pow(avanz[i].second - avanz[j].second,2));
                  aristas.push_back(make_pair(d,make_pair(i,j)));
               }
         
         V = avanzadas;Sats = satelites;
         sort(aristas.begin(), aristas.end()); // ordenamos las aristas de menor a mayor
         
         KrusKal();
    }
}