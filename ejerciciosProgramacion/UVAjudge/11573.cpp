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
int df[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

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

bool ok(int i,int j, int n1, int n2) {
    return 0 <= i && i < n1 && 0 <= j && j < n2;
}

int main(){
    int n1,n2, num;
    char numero;
    cin >> n1 >> n2;
    while(cin){
        adjList = vvii(n1*n2);
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2;j++){
                cin >> numero;
                num = numero - 48;
                for(int w = 0; w < 8; w++){
                    if(ok(i + df[w], j + dc[w], n1, n2)) {
                        if(w == num) adjList[i * n2 + j].push_back(make_pair(0, (i + df[w]) * n2 + (j + dc[w])));
                        else adjList[i * n2 + j].push_back(make_pair(1, (i + df[w]) * n2 + (j + dc[w])));
                    }
                }

            }
            cin.get();
        }
        dist = vi(n1*n2);
        int ncs;
        cin >> ncs;
        while(ncs--){
            cin >> ini1 >> ini2 >> dest1 >> dest2;
            dijkstra((ini1-1)*n2 + (ini2-1));
            cout << dist[(dest1 - 1) * n2 + (dest2 - 1)] << '\n';
        }
        cin >> n1 >> n2;
    }
    return 0;
}