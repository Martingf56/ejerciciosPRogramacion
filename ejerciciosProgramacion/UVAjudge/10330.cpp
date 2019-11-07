#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int s, t, c, n;
vector<vector<int>> adj, cap;
vector<bool> visited;
vector<int> parent;

void bfs(int s, int t) {
	queue<int> q;
	visited.assign(n+2, 0);
	q.push(s);
	parent[s] = -1; 
	visited[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (!visited[v] && (cap[u][v] > 0)) {
				parent[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

int sendFlow(int s, int t) {
	// Intentamos llegar de s a t
	bfs(s, t);
	if (!visited[t])
		return 0; // No pudimos
		// Buscamos capacidad m´as peque˜na en el camino
	int flow = 1000000, v = t;
	while (v != s) {
		flow = min(cap[parent[v]][v], flow);
		v = parent[v];
	}
	// Mandamos flujo
	v = t;
	while (v != s) {
		cap[parent[v]][v] -= flow;
		cap[v][parent[v]] += flow; // INVERSA
		v = parent[v];
	}
	return flow;
}

int main() {
    int n,cont = 1;
    int links;
    int i,j,capa;
    int B,D;
    while( cin >> n ){
        vector<int> capR(n);
        adj.assign(n+2, vector<int>());
		cap.assign(n+2, vector<int>(n+2,0));
        for(int  a = 0; a < n; a++)
            cin >> capR[a];
        cin >> links;
        while(links--){
            cin >> i >> j >> capa;
            adj[i].push_back(j);
            cap[i][j] += capa;
        }
        cin >> B >> D;
        for(int b = 0; b < B; b++){
            cin >> j;
            adj[0].push_back(j);
            cap[0][j] = 1000000;
        }
        for(int d = 0; d < D; d++){
            cin >> j;
            adj[j].push_back(n+1);
            cap[j][n+1] = 1000000;
        }
        parent.assign(n+2,-1);
        int flow = 0,ret=0;
        do{
            flow = sendFlow(0, n+1);
            ret +=flow;
        }while(flow > 0);

        cout << ret << '\n';
        
    }
	
	return 0;

}