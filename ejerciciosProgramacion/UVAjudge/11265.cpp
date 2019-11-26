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

struct line {
	pt v;
	T c;
	// from direction vector v and offset c
	line(pt v, T c) : v(v), c(c) {}
	// from equation ax + by = c
	line(T a, T b, T c) : v({ b,-a }), c(c) {} // from points p and q
	line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

	T side(pt p) { return cross(v, p) - c; }
	double dist(pt p) { return abs(side(p)) / abs(v); }

	pt proj(pt p) { return p - perp(v) * side(p) / sq(v); }
};


bool inter(line l1, line l2, pt& out) {
	T d = cross(l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v * l1.c - l1.v * l2.c) / d;  // requires floating-point coordinates
	return true;
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
	return orient(p, q, r) >= 0;
	// >= para puntos colineales
}

vector<pt> cutPolygon(pt a, pt b, vector<pt> const& P) {
	vector<pt> R;
	pt c;
	for (int i = 0; i < int(P.size()) - 1; i++) {
		double left1 = cross(b - a, P[i] - a),
			left2 = cross(b - a, P[i + 1] - a);
		if (left1 >= 0)
			R.push_back(P[i]);  // P[i] is on the left of ab
		if (left1 * left2 < 0) {  // edge (P[i], P[i+1]) crosses line ab
			inter({ P[i], P[i + 1] }, { a, b }, c);
			R.push_back(c);
		}
	}
	if (!R.empty())
		R.push_back(R[0]); // make R's first point = R’s last point

	return R;
}

int main() {
	int N, cont = 1;
	double W, H, x, y;
	
	while (cin >> N >> W >> H >> x >> y) {
		vector<pt> polygon;
		polygon.push_back({ 0,0 });
        polygon.push_back({ W,0 });
		polygon.push_back({ W,H });
		polygon.push_back({ 0,H });
        polygon.push_back({ 0,0 });
		pt fuente = { x,y };
		pt p1, p2;
		for (int i = 0; i < N; i++) {
			double x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			p1 = {x1,y1}; p2 = {x2,y2};
			if (ccw(p1, p2, fuente))
				polygon = cutPolygon(p1, p2, polygon);
			else
				polygon = cutPolygon(p2, p1, polygon);
		}
        double area = areaPolygon(polygon);
		cout << "Case #" << cont++ << ": " << fixed << setprecision(3) << area << '\n';
	}
	return 0;
}
