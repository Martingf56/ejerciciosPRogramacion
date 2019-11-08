

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int hora;
vector<int> horaVertice;
vector<int> alcanzable;
vector<pair<int, int>> sol;
vector<vector<int>> adj;

bool cmp(pair<int,int> a, pair<int, int> b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return a.second < b.second;
	else
		return false;
}

void dfs(int u, int uParent) {
	horaVertice[u] = alcanzable[u] = hora;
	hora++;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i]; if (v == uParent)continue;
		if (horaVertice[v] == 0) {
			dfs(v, u);
			if (alcanzable[v] > horaVertice[u]) {
				// La arista u-v es un puente
				pair<int, int> a;
				if (u < v) a = make_pair(u - 1, v - 1);
				else  a = make_pair(v - 1, u - 1);
				if (find(sol.begin(), sol.end(), a) == sol.end())
					sol.push_back(a);
			}
			alcanzable[u] = min(alcanzable[u], alcanzable[v]);
		}
		else alcanzable[u] = min(alcanzable[u], horaVertice[v]);
	}
}



int main() {
	int numNodos, nodoIni, nCon, nodo;

	cin >> numNodos;

	while (cin) {
		adj = vector<vector<int>>(numNodos + 1, vector<int>());
		for (int n = 0; n < numNodos; n++) {
			cin >> nodoIni;
			cin.ignore(); cin.ignore(); cin >> nCon; cin.ignore();
			for (int j = 0; j < nCon; j++) {
				cin >> nodo;
				adj[nodoIni + 1].push_back(nodo + 1);
			}
		}

		hora = 1;
		horaVertice = vector<int>(numNodos + 1, 0);
		alcanzable = vector<int>(numNodos + 1, -1);
		sol = vector<pair<int,int>>();

		for (int i = 1; i <= numNodos; ++i) {
			if (!horaVertice[i]) {
				dfs(i, 0);
			}
		}

		sort(sol.begin(), sol.end(), cmp);

		cout << sol.size() << " critical links\n";
		for (auto p : sol)
			cout << p.first << " - " << p.second << "\n";

		cin >> numNodos;
	}


	return 0;
}
