
#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<double,double>> v;


bool cmp(pair<double, double> a, pair<double, double> b) {
	return a.first < b.first;
}

pair<double, double> calcularPunto(pair<double, double> a, pair<double, double> b, double y) {
	double n, m, solx;
	m = (a.second - b.second) / (a.first - b.first);
	n = -m * a.first + a.second;
	solx = (y - n) / m;
	return (make_pair(solx, y));
}

double dist(pair<double, double> a, pair<double, double> b) {
	return sqrt(pow(abs(a.first - b.first), 2) + pow(abs(a.second - b.second),2));
}

double resuelve() {
	double redSum = 0,highestpodouble = -1;

	for (int i = v.size() - 1; i > 0; i-=1) {
		if (v[i-1].second > highestpodouble) {
			double d = dist(v[i-1], v[i]);
			if(highestpodouble != -1)
				 d -= dist(v[i], calcularPunto(v[i-1], v[i], highestpodouble));
			redSum += d;
			highestpodouble = v[i - 1].second;
		}
	}

	return redSum;
}


int main() {
	int numcs, numcor;
	double x, y;
	cin >> numcs;
	while (numcs--) {
		v = vector<pair<double,double>>();
		cin >> numcor;
		while (numcor--) {
	 		cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		sort(v.begin(), v.end(), cmp);

		cout << fixed << setprecision(2) << resuelve() << '\n';
	}
	return 0;
}
