#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;




using T = double;  // using T = int;
int N, L, H;

struct pt { 
	T x, y;
	pt operator+(pt p) const {
		return {x+p.x, y+p.y};
	} 
	pt operator-(pt p) const {
		return {x-p.x, y-p.y};
	} 
	
	pt operator*(T d) const {
		return {x*d, y*d};
	} 
	pt operator/(T d) const { 
		return {x/d, y/d};
	} // only for floating-point
	bool operator==(pt o) const { 
		return x == o.x && y == o.y; 
	} 
	bool operator!=(pt o) const { 
		return !(*this == o); 
	} 
	bool operator<(pt o) const { // sort points lexicographically
		if (x == o.x) return y < o.y;
		return x < o.x;
	} 
	//   bool operator<(pt o) const {   // #define EPS 1e-9 //       if (fabs(x - o.x) < EPS) return y < o.y; //       return x < o.x; //   } 
};

vector<pair<pt, pt>> lineas;

T sq(pt v) { return v.x * v.x + v.y * v.y; }

pt perp(pt p) { return { -p.y, p.x }; }

double abs(pt v) {
	return sqrt(sq(v));
}

T cross(pt v, pt w) {
	return v.x * w.y - v.y * w.x;
}

double dist(pt a, pt b) { // Euclidean distance
	return hypot(a.x - b.x, a.y - b.y);
}

struct line{ 
	pt v;  
	T c;
	// from direction vector v and offset c
	line (pt v, T c) : v(v), c(c) {} 
	// from equation ax + by = c
	line(T a, T b, T c) : v({b,-a}), c(c) {} // from points p and q
	line(pt p, pt q) : v(q-p), c(cross(v,p)) {}

	T side(pt p) { return cross(v,p) - c; }
	double dist(pt p) { return abs(side(p)) / abs(v); }

	pt proj(pt p) { return p - perp(v)*side(p)/sq(v); }    
};


void resuelve() {
	double maxi  = 1000000;
	for (int i = 0; i < lineas.size(); i++) {
		pt A = lineas[i].first; pt B = lineas[i].second;
		maxi = min(maxi, i % 2 ? B.x:(L - B.x));
		
		if (i == lineas.size() - 1)
			break;
		pt aux ;
		if(i % 2 == 0 && lineas[i+1].second.x >= B.x)
			aux = lineas[i+1].second;
		else if(i % 2 == 1 && lineas[i+1].second.x <= B.x)
			aux = lineas[i+1].second;
		else{
			line l = line(lineas[i + 1].first, lineas[i + 1].second);
			aux = l.proj(B);
		}

		maxi = min(maxi, dist(B,aux));
	}
	cout << fixed << setprecision(2) << maxi << '\n';
}


int main() {
	cin >> N;
	int cont = 1;
	while (cin) {
		cin >> L >> H;
		int yi, xf, yf;
		double maxi  = 1000000;
		pair<pt,pt> lineaAnt;
		pt A, B;
		cin >> yi >> xf >> yf;
		A.x = 0;A.y = yi; B.x = xf; B.y = yf;
		maxi = L - B.x;
		lineaAnt ={A,B};
		for (int i = 1; i < N; i++) {
			cin >> yi >> xf >> yf;
			if(i % 2 == 0) A.x = 0;
			else A.x = L;
			A.y = yi; B.x = xf; B.y = yf;
			maxi = min(maxi, i % 2 ? B.x:(L - B.x));
			line l = line(A,B);
			pt p = l.proj(lineaAnt.second);
			double d;
			if(i % 2){
				if(p.x > B.x)
					d = l.dist(lineaAnt.second);
				else
					d = dist(lineaAnt.second,B);
			}
			else{
				if(p.x < B.x)
					d = l.dist(lineaAnt.second);
				else
					d = dist(lineaAnt.second,B);
			}
 			maxi = min(maxi, d);
			lineaAnt = {A,B};
		}

		cout << fixed << setprecision(2) << maxi << '\n';
		cin >> N;
		cont++;
	}
	return 0;
}
