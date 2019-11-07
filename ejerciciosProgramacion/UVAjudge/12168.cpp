#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<int>> grafo; // dirigido, tama�o M
vector<int> match, vis;

int aug(int l) { // Devuelve 1 si encuentra un augmenting path para el matching M representado en match.
	if (vis[l]) return 0;
	vis[l] = 1;
	for (auto r : grafo[l]) {
		if (match[r] == -1 || aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}
int berge_mcbm() {
	int mcbm = 0;
	match.assign(N + M, -1);
	for (int l = 0; l < M; l++) {
		vis.assign(M, 0);
		mcbm += aug(l);
	}
	return mcbm;
}


int main(){
    int cases, c, d ,v;
	cin >> cases;
	for (int n = 0; n < cases; n++) {
		cin >> c >> d >> v;
		vector<pair<int,int>> g ,p;
		for (int i = 0; i < v; i++) {
			char pet,pet2;
			int num,num2;
			cin >> pet >> num >> pet2 >> num2;
			if (pet == 'D') 
				p.push_back(make_pair(num,num2));
			else 
				g.push_back(make_pair(num,num2));
			
		}
		grafo = vector<vector<int>>(v,vector<int>());
		for(int a = 0; a < g.size(); a++)
			for(int b = 0; b < p.size(); b++)
				if(g[a].first == p[b].second || p[b].first == g[a].second)
					grafo[a].push_back(b);

		M = g.size(); N = p.size();
		cout << v - berge_mcbm() << '\n';
	}
	return 0;
}