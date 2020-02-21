#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> corrientes;
int ini1,ini2,dest1,dest2;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvii = vector<vector<ii>>;
vvii adjList; vi dist;

void dijkstra(int s) {
	dist.assign(adjList.size(), 1000000);
	dist[s] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (auto a : adjList[u]) {
			if (dist[u] + a.first < dist[a.second]) {
				dist[a.second] = dist[u] + a.first;
				pq.push({ dist[a.second], a.second });
			}
		}
	}
} 

int main(){
    int ncs,F,C;
    cin >> ncs;
    while(ncs--){
        int nodo,valor;
        cin >> F;
        cin >> C;
        adjList = vvii(F*C);
        dist = vi(F*C);
        cin >> valor;
        for(int i = 0; i < F;i++)
            for(int j = 0; j < C;j++){
                nodo = F*i + j;
                if(nodo != F*(F-1) + C - 1)
                    cin >> valor;
                if(j != 0)
                    adjList[nodo].push_back({valor,F*i + j-1});
                if(j != C - 1)
                    adjList[nodo].push_back({valor,F*i + j + 1});
                if(i != 0)
                    adjList[nodo].push_back({valor,F*(i-1)+j});
                if(i != F - 1)
                    adjList[nodo].push_back({valor,F*(i+1) + j});                
            }

        dijkstra(0);
        cout << dist[F*C - 1] << '\n';
    }
    return 0;
}