#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int ini1,ini2,dest1,dest2;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvii = vector<vector<ii>>;


void dijkstra(int s, vi &dist, vvii adjList) {
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
    int ncs; 
    cin >> ncs;
    while(ncs--){
        int N,M,s,t,p;
        cin >> N >> M >> s >> t >> p;
        vvii adjList(N), radjList(N); 
        vi dist(N),rdist(N);
        for(int i = 0; i < M; i++){
            int u,v,c;
            cin >> u >> v >> c;
            u--; v--;
            adjList[u].push_back({c,v});
            radjList[v].push_back({c,u});
        }
        dijkstra(s-1,dist,adjList);
        dijkstra(t-1,rdist,radjList);

        int maxi = -1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < adjList[i].size();j++){
                int coste = adjList[i][j].first;
                int conexion = adjList[i][j].second;
                if(coste + dist[i] + rdist[conexion] <= p)
                    if(coste > maxi)
                        maxi = coste;
            }
        }

        cout << maxi << '\n';
    }

    return 0;
}