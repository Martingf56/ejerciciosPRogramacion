#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grafo(200);
int color[200];

bool resuelve(int n){
    for(int i = 0;i < n;i++)
        color[i] = -1;
    int p,pos;
    bool bip = true;
    queue<int> col;
    col.push(0);
    color[0] = 1;
    while(!col.empty() && bip) {
        pos = col.front(); col.pop();
        for(int i = 0; i < grafo[pos].size();i++){
            p = grafo[pos][i];
            if(color[p] == -1) {
                color[p] = color[pos] == 1? 0: 1;
                col.push(p);
            }
            else if(color[p] == color[pos]){
                bip = false;
                break;
            }
        }
    }
    return bip;
}

int main(){
    int n,ed,in,dest;
    cin >> n;
    while(n != 0){
        cin >> ed;
        while(ed--){
            cin >> in >> dest;
            grafo[in].push_back(dest);
            grafo[dest].push_back(in);
        }
        if(resuelve(n))
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
        
        grafo = vector<vector<int>>(200);
        cin >> n;
    }
    return 0;
}