#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> matriz;
vector<vector<bool>> visited;
int finali,finalj, F, C,solve = -1;
int df[] = {1,0,-1,0}, dc[] = {0,1,0,-1};

bool ok(int i,int j){
    return 0 <= i && i < F && 0 <= j && j < C;
}

void dfs(int i, int j, int cont){
    if(cont > solve && solve != -1) 
        return;
    visited[i][j] = true;
    cont += matriz[i][j];
    if(i == finali && j == finalj) {
        solve = solve == -1?cont: min(cont,solve);
        return;
    }
    for(int k = 0; k < 4; k++){
        int ni = i + df[k], nj = j + dc[k];
        if(ok(ni,nj) && !visited[ni][nj]){
            dfs(ni,nj,cont);
            visited[ni][nj] = false;
        }
    } 
}   

int resuelve(){
    dfs(0,0,0);
    return solve;
}

int main(){
    int ncs;
    cin >> ncs;
    while(ncs--){
        cin >> F;
        cin >> C;
        matriz = vector<vector<int>>(F,vector<int>(C));
        visited= vector<vector<bool>>(F,vector<bool>(C));
        for(int i =0; i < F;i++)
            for(int j = 0; j < C;j++)
                cin >> matriz[i][j];
        finali = F - 1;finalj= C - 1;
        cout << resuelve() << '\n';
    }
    return 0;
}