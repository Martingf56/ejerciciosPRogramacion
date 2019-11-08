#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

int maxN, maxD;

void bfs(int s) {
	queue<int> q;
	int dias = 1,cont = 1;
	visited[s] = true;
	q.push(s);
	while (!q.empty()) {
		int suma = 0;
		while (cont--) {
			int v = q.front(); q.pop();
			for (int w : adjList[v]) {
				if (!visited[w]) {
					suma++;
					visited[w] = 1;
					q.push(w);
				}
			}
		}
		if (suma > maxN) {
			maxN = suma;
			maxD = dias;
		}
		cont = suma;
		dias++;
	}
}

int main() {
	int numEmpleados;
	while (cin >> numEmpleados) {
		adjList = vector<vector<int>>(numEmpleados,vector<int>());
		int numAmigos, amigo, numCasos, primero;
		for (int i = 0; i < numEmpleados; i++) {
			cin >> numAmigos;
			for (int j = 0; j < numAmigos; j++) {
				cin >> amigo;
				adjList[i].push_back(amigo);
			}
		}
		cin >> numCasos;
		for (int i = 0; i < numCasos; i++) {
			visited = vector<bool>(numEmpleados, false);
			maxD = maxN = -1;
			cin >> primero;
			bfs(primero);
			cout << maxN << " ";
			if (maxN)  cout << maxD;
			cout << '\n';
		}
		
	}
	
	return 0;
}