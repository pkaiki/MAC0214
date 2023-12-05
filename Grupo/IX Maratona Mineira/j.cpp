#include <bits/stdc++.h>
#define int long long
using namespace std;

struct point{
  int x, y;
  point operator-(const point &other) const{
    return {x-other.x, y-other.y};
  }
  int operator^(const point &other) const{
    return x*other.y - y*other.x;
  }
};

bool isleft(point A, point B, point C){
  return ((B-A)^(C-A)) > 0;
}

bool iseq(point A, point B, point C){
  return ((B-A)^(C-A)) == 0;
}

bool isright(point A, point B, point C){
  return ((B-A)^(C-A)) < 0;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<point> p(n);
  for(int i=0; i<n; i++){
    int x, y; cin >> x >> y;
    p[i] = {x, y};
  }

  point c;
  int x, y; cin >> x >> y;
  c = {x, y};

  for(int i=0; i<n; i++){
    if(iseq(p[i], p[(i+1)%n], c)){
      cout << "N\n";
      return 0;
    }
  }

  bool isL = isleft(p[0], p[(1)%n], c);
    
  for(int i=0; i<n; i++){
    if(isleft(p[i], p[(i+1)%n], c) != isL){
      cout << "N\n";
      return 0;
    }
  }

  cout << "S\n";
  return 0;
}
 
