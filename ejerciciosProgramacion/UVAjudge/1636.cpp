#include <iostream>
#include <string>

using namespace std;



int main(){
    string leer;
    double muerto,vive;
    cin >> leer;
    while(cin){
        double vacio = 0;
        muerto = 0;vive = 0;
        int cont = leer.length()-1;
        for(int i = 0; i < leer.length(); i++){
            if(leer[i] == '0'){
                vacio++;
                if(leer[cont] == '0')
                    vive++;
            }
            else if(leer[i ] == '1'){
                if(leer[cont] == '0')
                    muerto++;
            }
            cont = i;
        }
        double probM = vacio / (double)leer.length();
        double probV = vive / (vive+muerto); 
        if(probM > probV)
            cout << "ROTATE\n";
        else if( probM < probV)
            cout << "SHOOT\n";
        else 
            cout << "EQUAL\n"; 
        cin >> leer;
    }

    return 0;
}