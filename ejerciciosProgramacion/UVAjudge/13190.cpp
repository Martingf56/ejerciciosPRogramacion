#include <iostream>
#include <string>

using namespace std;

int n,nmen;
typedef struct {
	string nombre;
	int min;
	int sum;
}Medicamento;
Medicamento med[3000];


void resuelve(int num, int min) {
	int m;
	while (num < n) {
		m = -1;
		for (int i = 0; i < nmen; ++i) {
			if (med[i].sum == min && num < n) {
				cout << med[i].sum << " " << med[i].nombre << '\n';
				med[i].sum += med[i].min;
				num++;
			}
			if (m == -1 || m > med[i].sum)
				m = med[i].sum;
		}
		min = m;
	}
}

int main() {
	int ncs, i;
	int min;
	cin >> ncs;
	while (ncs--) {
		cin >> nmen >> n;
		cin >> med[0].nombre >> med[0].min; med[0].sum = med[0].min;
		min = med[0].min;
		i = 1;
		while (i < nmen){
			cin >> med[i].nombre >> med[i].min; med[i].sum = med[i].min;
			if (min > med[i].min)
				min = med[i].min;
			i++;
		}
		resuelve(0, min);
	}

	return 0;
}