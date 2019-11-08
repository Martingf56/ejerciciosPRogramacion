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

    void add(int a, int b, int val){
        add(a,val);
        add(b+1,-val);
    }

	int getSum(int a, int b){
		return getSum(b) - getSum(a - 1);
	}
	int getValue(int pos) {
		return getSum(pos);
	}
	void setValue(int pos, int val) {
		add(pos, val - getValue(pos));
	}
};

int main(){
    int N,potencia, a ,b, c;
    int cont = 0;
	string option;
	cin >> N;
	while (N != 0) {
		FenwickTree ft = FenwickTree(100000);
        for(int i = 0; i < N; i++){
            cin >> option;
            if(option == "Q"){
                cin >> a;
		        cout << ft.getValue(a) <<'\n';
            }
            else if(option == "B"){
                cin >> a >> b >> c;
                ft.add(a,b,c);
            }
        }
		cont++;
		cin >> N;
	}
    return 0;
}
/* 
9
B 5 5 2
B 8 8 2
B 10 13 1
Q 8
B 8 13 1
Q 8
B 15 16 1
B 2 10 1
Q 8
9
B 5 5 2
B 8 8 2
B 10 13 1
Q 8
B 8 13 1
Q 8
B 15 16 1
B 2 10 1
Q 8
0

*/