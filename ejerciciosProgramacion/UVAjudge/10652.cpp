#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;




using T = double;  // using T = int;
int N;

struct pt {
	T x, y;
	pt operator+(pt p) const {
		return { x + p.x, y + p.y };
	}
	pt operator-(pt p) const {
		return { x - p.x, y - p.y };
	}

	pt operator*(T d) const {
		return { x * d, y * d };
	}
	pt operator/(T d) const {
		return { x / d, y / d };
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

// rotate p by a certain angle a counter-clockwise around origin
pt rotate(pt p, double a) {
	return { p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a) };
}/*  */

struct board {
	pt b1, b2, b3, b4;
};

double areaPolygon(vector<pt> const& p) {
	double area = 0.0;
	for (int i = 0; i < int(p.size()) - 1; ++i) {
		area += cross(p[i], p[i + 1]);
	}
	return abs(area) / 2.0;
}

T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

// devuelve true si r está en el lado izquierdo de la línea pq
bool ccw(pt p, pt q, pt r) {
	return orient(p, q, r) > 0;
	// >= para puntos colineales
}
// devuelve un polígono con la envolvente convexa de la nube de puntos P
vector<pt> convexHull(vector<pt>& P) {
	int n = int(P.size()), k = 0;
	vector<pt> H(2 * n);
	sort(P.begin(), P.end());// build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	} // build upper hull
	for (int i = n - 2, t = k + 1; i >= 0; --i) {
		while (k >= t && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}


int main() {
	int N, numberBoards;
	double boardsArea, result;
	string str;
	cin >> N;
	while (N--) {
		cin >> numberBoards;
		boardsArea = 0;
		vector<pt> polygon = vector<pt>();
		for (int i = 0; i < numberBoards; i++) {
			double x, y, w, h, angle;
			cin >> x >> y >> w >> h >> angle;
			boardsArea += (w * h);
			angle = -angle * acos(-1) / 180;//Pasar a radianes
            pt p1 = {w/2,h/2}; pt p2 = {w/2,-h/2};
            pt p3 = {-w/2,-h/2};pt p4 = {-w/2,h/2};
			p1 = rotate(p1, angle); p2 = rotate(p2, angle); p3 = rotate(p3, angle); p4 = rotate(p4, angle);
            p1.x += x; p1.y += y; p2.x += x; p2.y += y;
            p3.x += x; p3.y += y; p4.x += x; p4.y += y;
			polygon.push_back(p1);//arribaIzq
			polygon.push_back(p2);//arribaDer
			polygon.push_back(p3);//abajoIzq
			polygon.push_back(p4);//abajoDer
		}
		polygon = convexHull(polygon);
		double AreaPolygon = areaPolygon(polygon);
		result = boardsArea * 100 / AreaPolygon;
		cout << fixed << setprecision(1) <<  result  << " %\n";
	}
	return 0;
}
