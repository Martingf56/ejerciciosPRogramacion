#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int ncs;
    cin >> ncs;
    while(ncs--){
        int floors,piso;
        vector<int> azules, rojos;
        cin >> floors;
        for(int i = 0; i < floors; i++){
            cin >> piso;
            if(piso < 0)
                rojos.push_back(abs(piso));
            else 
                azules.push_back(piso);
        }
        sort(azules.begin(),azules.end());
        sort(rojos.begin(),rojos.end());

        int conta = 0,contr = 0,tam = 0,ultpiso = 0;
        bool ultcolor, exit = false;
        if(!azules.size()) ultcolor = true;
        else if(!rojos.size()) ultcolor = false;
        else ultcolor = azules[conta] > rojos[contr];
        while((contr < rojos.size() || conta < azules.size()) && !exit) {  
            if((contr >= rojos.size() || conta >= azules.size()))
                exit = true;

            if(!ultcolor){
                if(exit){
                    if(azules[azules.size()-1] > ultpiso) tam++;
                    break;
                }
                if(azules[conta] > ultpiso){
                    ultpiso = azules[conta]; ultcolor = true;
                    tam++;
                }
                conta++;
            }
            else {
                if(exit){
                    if(rojos[rojos.size()-1] > ultpiso) tam++;
                    break;
                }
                if(rojos[contr] > ultpiso){
                    ultpiso = rojos[contr]; ultcolor = false;
                    tam++;
                }
                contr++;
            }
           
        }

        cout << tam << '\n';

    }
}