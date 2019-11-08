#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

vector<vector<int>> adjM;
int numnodos,mayor;

void floyd() {
	for(int k = 0; k < mayor; k++)
		for(int i = 0; i < mayor;i++)
			for(int j = 0; j < mayor; j++)
				if (adjM[i][k] + adjM[k][j] < adjM[i][j]) 
					adjM[i][j] = adjM[i][k] + adjM[k][j];
}


double resuelve() {
	double suma = 0;
	floyd();
	for (int i = 0; i < mayor; i++)
		for (int w = 0; w < mayor;w++) 
            if( adjM[i][w] != 100000)
			    suma += adjM[i][w];
            
	return suma;
}


int main() {
	int n1,n2,cont=1;
	cin >> n1 >> n2;
	while (n1 != 0 && n2 != 0) {
		adjM = vector<vector<int>>(100,vector<int>(100,100000));
		numnodos = 0;mayor=0;
		while (n1 != 0 && n2 != 0) {
            if(adjM[n1-1][n1-1] == 100000)
                numnodos++;
			mayor = max(mayor,max(n1,n2));
			adjM[n1-1][n2-1] = 1;
			adjM[n1-1][n1-1] = 0;
			cin >> n1 >> n2;
		}
		for (int i = 0; i < 100; i++)
			adjM[i][i] = 0;

        cout << "Case " << cont << ": average length between pages = " 
		<< fixed << setprecision(3)<< (double)(resuelve() / (double)(numnodos * (numnodos - 1 ))) << " clicks\n";
		cin >> n1 >> n2;
        cont++;
	}
	return 0;
}