#include <bits/stdc++.h>
#define int long long
using namespace std;

using coord = long double;
const long double pi = acos(-1);
const coord EPS = 1e-8;

int sign(coord x) { return (x > EPS) - (x < -EPS); }
coord sq(coord x) { return x * x; }

struct point {
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point p){ return {x + p.x, y + p.y}; }
	inline point operator-(point p){ return {x - p.x, y - p.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(point p){ x = p.x, y = p.y; }

	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(tht)
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(tht), this -> p

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  1 left, 0 over, -1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){ return point(-y, x);}
	inline point rot(long double ang){ return point(cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y); 		}
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }
	
	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; } // lex_sort
	inline bool operator==(point p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

struct circle{
	point c; coord r;
	circle() {} circle(point _c, coord _r): c(_c), r(_r) {}

	vector<point> get_tan(point p){ // tangent points
		long double d2 = (c - p).norm2();
		if (sign(d2 - r * r) < 0) return {};
		if (sign(d2 - r * r) == 0) return {p};
		long double tht = acos(sqrt((r*r)/d2));
		point vec = ((p - c)/(p - c).norm()) * r;
		return {c + vec.rot(tht),c + vec.rot(-tht)};
	}
};	

void solve(){
  point current, destination;
  circle cir;

  cin >> current.x >> current.y;
  cin >> destination.x >> destination.y;
  cin >> cir.c.x >> cir.c.y >> cir.r;
  cin >> cir.c.x >> cir.c.y >> cir.r;

  auto current_tan = cir.get_tan(current);
  auto destination_tan = cir.get_tan(destination);

  point p1, p2;

  long double cur_min = (current_tan[0] - destination_tan[0]).norm(); 

  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      if(cur_min >= (current_tan[i] - destination_tan[j]).norm()){
        cur_min = (current_tan[i] - destination_tan[j]).norm();
        p1 = current_tan[i];
        p2 = destination_tan[j];
      }
    }
  }

  long double ans = (current - p1).norm() + (destination- p2).norm(); 

  long double dist2_tan = (p1 - p2).norm2();

  ans += cir.r * acos(1.0 - (dist2_tan/(2.0 * cir.r * cir.r)));

  cout << fixed << setprecision(10) << ans << "\n";

}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
