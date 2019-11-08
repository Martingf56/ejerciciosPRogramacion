#include <iostream>
#include <vector>
using namespace std;

class FenwickTree{
	vector<int> ft;
	public:FenwickTree(int n) {
		ft.assign(n + 1, 0); 
	}
	int getSum(int b) {
		int ret = 0;
		while (b) {
			ret += ft[b];
			b -= (b & -b);
		}
		return ret;
	}

	void add(int pos,int val){
		while (pos < ft.size()) {
			ft[pos] += val; pos += (pos & -pos); 
		} 
	}

	int getSum(int a, int b){
		return getSum(b) - getSum(a - 1);
	}
	int getValue(int pos) {
		return getSum(pos) - getSum(pos - 1);
	}
	void setValue(int pos, int val) {
		add(pos, val - getValue(pos));
	}
};
int main() {
	int N,potencia, a ,b;
	int cont = 0;
	string option;
	cin >> N;
	while (N != 0 && cont < 3) {
		FenwickTree ft = FenwickTree(N);
		for (int i = 1; i <= N; i++) {
			cin >> potencia;
			ft.add(i, potencia);
		}
		cout << "Case " << cont + 1 << ":\n";
		cin >> option;
		while (option != "END") {
			cin >> a >> b;
			if (option == "M")
				cout << ft.getSum(a, b) << '\n';
			else if (option == "S")
				ft.setValue(a, b);

			cin >> option;
		}
		cont++;
		cout << '\n';
		cin >> N;
	}
	

	return 0;
}