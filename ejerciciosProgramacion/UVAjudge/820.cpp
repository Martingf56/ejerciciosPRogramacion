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
	visited = vector<bool>(n,false);
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
    int cont = 1;
    int s,t,c;
    int o,d,cant;
    cin >> n;
    while(n != 0){
        cin >> s >> t >> c;
		cap = vector<vector<int>>(n, vector<int>(n));
		adj = vector<vector<int>>(n);
        while(c--){
            cin >> o >> d >> cant;
			o--;d--;
            adj[o].push_back(d); adj[d].push_back(o);
            cap[o][d] += cant; cap[d][o] += cant;
        }
        int flow = 0,ret=0;
      	 parent = vector<int>(n);
        do{
            flow = sendFlow(s-1, t-1);
            ret += flow;
        }while(flow > 0);
        cout << "Network " << cont++ << '\n';
        cout << "The bandwidth is " << ret << ".\n\n";
        cin >> n;
    }

	
	return 0;

}