#include <iostream>
#include <vector>
#include <math.h>


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
	vector<pair<float,float>> hole, gofre;
	float x,y; // M parte izquierda, N parte derecha
	int S,V;
	while (cin >> M) {
		cin >> N >> S >> V;
		hole = vector<pair<float, float>>(N);
		gofre = vector<pair<float, float>>(M);
		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			gofre[i] = make_pair(x, y);
		}
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			hole[i] = (make_pair(x, y));
		}
		grafo = vector<vector<int>>(N + M);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (S >= sqrt(pow((gofre[i].first - hole[j].first),2) + pow((gofre[i].second - hole[j].second),2))/V) {
					grafo[i].push_back(M + j);
				}
			}
		}
		
		cout << M - berge_mcbm() << '\n';
	}
	return 0;
}