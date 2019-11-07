#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iomanip>


using namespace std;

vector<pair<int,double>> entrada;
vector<int> cantidad;
vector<double> soluciones(100);
int maxi;

void resuelve() {
    int a = 1;
    for(int i = 0; i < entrada.size(); i++){
        for(a = 1; a <= maxi; a++){
            if(i == 0)
                soluciones[a] = entrada[i].second * a;
            else if(a <= entrada[i].first)
                    soluciones[a] = min(soluciones[a],entrada[i].second);
            else 
                soluciones[a] = min(soluciones[a], entrada[i].second + soluciones[a - entrada[i].first]);               
            
        }
    }
}

int main(){
    double precio;int tam,n;
    string str;
    cin >> precio >> tam;
    int cont=1;
    while(cin){
        entrada.push_back(make_pair(1,precio));
        for(int i = 0; i < tam; i++){
            cin >> n >> precio;
            entrada.push_back(make_pair(n,precio));
        }
        getline(cin,str);
        getline(cin,str);
        istringstream iss(str);
        int numero;
        maxi = -1;
        while (iss >> numero) {
            maxi = max(maxi,numero);
            cantidad.push_back(numero);
        }
    
        resuelve();
        cout << "Case " << cont << ":\n";
        for(int b = 0; b < cantidad.size();b++)
            cout << "Buy "<< cantidad[b] << " for $" << fixed << setprecision(2) << soluciones[cantidad[b]] <<'\n'; 
        cont++;
        cin >> precio >> tam;
        cantidad.clear();
        entrada.clear();
        soluciones.clear();
    }
    return 0;
}