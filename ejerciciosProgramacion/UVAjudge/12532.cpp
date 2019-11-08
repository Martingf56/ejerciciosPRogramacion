#include <iostream>
#include <vector>
using namespace std;

int INF = 100000;

class FenwickTree{

	public:
	vector<long long int> ft;
	FenwickTree(int n) {
		ft.assign(n + 1, 0);
	}
	long long int getSum(int b) {
		long long int ret = 0;
		while (b) {
			ret += ft[b];
			b -= (b & -b);
		}
		return ret;
	}

	void add(int pos,long long int val){
		while (pos < ft.size()) {
			ft[pos] += val; pos += (pos & -pos);
		}
	}

	long long int getSum(int a,int b){
		return getSum(b) - getSum(a - 1);
	}

	long long int getValue(int pos) {
		return getSum(pos) - getSum(pos - 1);
	}

	void setValue(int pos, long long int val) {
		add(pos, val - getValue(pos));
	}
};
int main() {
	int N,K,potencia, a ,b;
	long long int negatives;
	string option, ret;
	cin >> N >> K;
	while (cin) {
		ret = "";
		FenwickTree ft = FenwickTree(N);
		for (int i = 1; i <= N; i++) {
			cin >> potencia;
			if(potencia < 0) ft.add(i, 1);
			else if (potencia == 0) ft.add(i, -INF);
			else ft.add(i, 0);

		}
		for (int i = 0; i < K; i++) {
			cin >> option >> a >> b;
			if (option == "C"){
				if(b < 0) ft.setValue(a, 1);
				else if (b == 0) ft.setValue(a, -INF);
				else ft.setValue(a, 0);

				//cout << ft.getValue(a) << "\n";
			}
			else if (option == "P") {
				negatives = ft.getSum(a, b);
				//cout << negatives << "\n";
				if (negatives < 0)
					ret += "0";
				else
					ret += (negatives % 2 == 0) ? "+" : "-";
			}

		}
		cout << ret << "\n";
		cin >> N >> K;
	}


	return 0;
}
