#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dist;
vector<bool> visited;

int n1, n2, r;


int bfs() {
	queue<int> q;
	vector<int> adjList(3);
	dist[n1] = 0; visited[n1] = true;
	q.push(n1);
	if (n1 == n2) {
		return 0;
	}
	while (!q.empty()) {
		int v = q.front(); q.pop();
		adjList[0] = v + 1; adjList[1] = v * 2; adjList[2] = v / 3;
		for (int w : adjList) {
			w %= 10000;
			if (w == n2) return (dist[v] + 1);
			if (!visited[w]) {
				dist[w] = dist[v] + 1;
				visited[w] = 1;
				q.push(w);
			}
		}
	}
}

int resuelve() {
	
	return 0;
}


int main() {
	cin >> n1 >> n2;
	while (cin) {
		dist = vector<int>(10000);
		visited = vector<bool>(10000, false);
		cout << bfs() <<  "\n";
		cin >> n1 >> n2;
	}
	return 0;
}