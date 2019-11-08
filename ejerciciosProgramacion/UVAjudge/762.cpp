#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

map<string, vector<string>> adList;
map<string,int> visitado;

void resuelve(string in,string dest){
    string punto;
    bool enc = false;
    queue<string> col;
    visitado[in] = 0;
    col.push(in);
    while(!col.empty() && !enc) {
        punto = col.front(); col.pop();
        for(string s : adList[punto]){
            if(!visitado[s]){
                visitado[s] = visitado[punto] + 1;
                if(punto == dest){
                    enc = true;
                    break;
                }
                col.push(s);
            }
        }
    }
}

int main(){
    int n;
    string uno,dos;
    cin >> n;
    while(cin){
        for(int i = 0; i < n; i++){
            cin >> uno >> dos;
            adList[uno].push_back(dos);
            adList[dos].push_back(uno);
        }
        cin >> uno >> dos;
        resuelve(uno,dos);
        cin >> n;
        adList = map<string,vector<string>>();
    }
    return 0;
}