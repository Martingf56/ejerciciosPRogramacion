#include <iostream>
#include <vector>

using namespace std;

vector<int> entrada(51);
vector<vector<int>> solucion(501,vector<int>(51));
int puntos;


void resuelve(){
    for(int i =0; i < entrada.size(); i++){
       for(int j = entrada[i]; j <= puntos;i++){
           if(j == entrada[i]){//si es igual solo debe tener este  ---MALLLL
                solucion[j] = vector<int>();
                solucion[j].push_back(entrada[i]);
            }
           /* else if( j > entrada[i]){
                if(solucion[ j - entrada[i] ].size() != 0 ){//si es posible la suma
                    //si existe la entrada o si es mejor que el anterior
                    if(1 + solucion[ j - entrada[i] ].size() <= solucion[j].size() || solucion[j].size() == 0){
                        solucion[j].push_back(entrada[i]);
                        auto it = solucion[j].begin(),v1 = solucion[j - entrada[j - entrada[i]]].begin(),
                        v2 = solucion[j - entrada[j - entrada[i]]].begin();
                        solucion[j].insert(it+1, v1, v2);
                    }
                }
            }  */          
        }
    }
}

int main(){
    int tam;
    cin >> puntos >> tam;
    while(cin){
        //rellenar entrada
        for(int i = 0; i < tam; i++)
            cin >> entrada[i];
        resuelve();
        //limpieza de vectores;
        entrada.clear();
        solucion.clear();

        cin >> puntos >> tam;
    }
    return 0;
}