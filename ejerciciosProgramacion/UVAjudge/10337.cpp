#include <iostream>


using namespace std;


typedef int tMatriz[10][1005];
tMatriz matriz;
int tam;

int resuelve(){
	int suma = 0;
	int sub,baj,seg;
	for(int i = tam - 1; i >= 0; i++){
		for(int j = 9; j >= 0;j--){
			if(i == tam - 1){
				if(j == 9)
					matriz[i][j] = min(60 + (-1 *matriz[j][i]), 30 + (-1 *matriz[j][i])+ matriz[j][i+1]);
				else
					matriz[i][j] = min(60 + (-1 *matriz[j][i]), min(30 + (-1 *matriz[j][i])+ matriz[j][i+1],
																					20 + (-1 *matriz[j][i])+ matriz[j-1][i+1]));
			}
			else{
				if(j == 9)
					matriz[i][j] = min(60 + (-1 *matriz[j][i]) + matriz[j+1][i+1], 30 + (-1 *matriz[j][i])+ matriz[j][i+1]);
				else
					matriz[i][j] = min(60 + (-1 *matriz[j][i]) + matriz[j+1][i+1], min(30 + (-1 *matriz[j][i])+ matriz[j][i+1],
																							20 + (-1 *matriz[j][i])+ matriz[j-1][i+1]));
			}	
		}
	}
	return suma;
}


int main(){
	int ncs;
	cin >> ncs;
	while (ncs--){
		cin >> tam; tam /=100;
		for(int j = 0; j < 10;j++)
			for(int i =0;i < tam;i++)
				cin >> matriz[j][i];
	}
	
}