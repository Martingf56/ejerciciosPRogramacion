#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int resuelve(vector<int> cabezas,vector<int> caballeros,bool &completo) {
	int a = 0,suma = 0;
	int cont = 0;
	while (a < caballeros.size() && cont < cabezas.size()) {
		if (cabezas[cont] <= caballeros[a]) {
			suma += caballeros[a];
			cont++;
		}
		a++;
	}
	completo = (cont == cabezas.size());
	return suma;
}

int main() {
	int n,m;
	cin >> n >> m;
	while (n != 0 && m != 0) {
		vector<int> cabezas(n), caballeros(m);
		for (int i = 0; i < n; i++) 
				cin >> cabezas[i];
			
		for (int j = 0; j < m; j++) 
			cin >> caballeros[j];
			
		if (n <= m) {
			sort(cabezas.begin(), cabezas.end());
			sort(caballeros.begin(), caballeros.end());
			bool doom ;
			int suma = resuelve(cabezas,caballeros, doom);
			if(doom)
				cout << suma << '\n';
			else
				cout << "Loowater is doomed!\n";
		}
		else
			cout << "Loowater is doomed!\n";

		cin >> n >> m;
	}
	return 0;
}