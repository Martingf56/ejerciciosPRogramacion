
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V; // vértices del grafo completo
vector<vector<int>> memo; // tabla de DP
vector<vector<int>> dist;

// devuelve el coste de ir desde pos al origen (el vértice 0)
// pasando por todos los vértices no visitados (con un bit a 0)
int tsp(int pos, int visitados) {
	if (visitados == (1 << V) - 1) // hemos visitado ya todos los vértices
		return dist[pos][0]; // volvemos al origen
	if (memo[pos][visitados] != -1)
		return memo[pos][visitados];

	int res = 1000000000;
	for (int i = 1; i < V; ++i)
		if (!(visitados & (1 << i))) // no hemos visitado vértice i
			res = min(res, dist[pos][i] + tsp(i, visitados | (1 << i)));
	return memo[pos][visitados] = res;
}

int main() {
	int ncs, tam1,tam2,posx,posy,num;
    cin >> ncs;
    while(ncs--){
        cin >> tam1 >> tam2;
        cin >> posx >> posy;
        cin >> num;
        vector<pair<int, int>> position(num + 1);
		position[0] = make_pair(posx,posy);
        int x,y,i =1;
        while(i <= num){
            cin >> x >> y;
            position[i] = make_pair(x,y);
            ++i;
        }

        dist = vector<vector<int>>(num+1,vector<int>(num+1,0));
        for (int a = 0; a < num + 1; a++) {
			for (int b = a + 1; b < num + 1; b++) {
				dist[a][b] = abs(position[a].first - position[b].first) + abs(position[a].second - position[b].second);
				dist[b][a] = dist[a][b];
			}
		}
		V = num + 1;
		memo.assign(V, vector<int>(1 << V, -1));
		cout << "The shortest path has length " << tsp(0, 1 << 0) << '\n';
    }
}

