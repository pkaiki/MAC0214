#include <bits/stdc++.h>
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int g; cin >> g;
  string s; cin >> s;

  int now = 0, ang[2] = {0, 0};
  bool flag = false;
  for(char c : s){
    int old_now = now;

    if(c == 'E'){
      now -= g;

      if(now <= -360){
        flag = true;
        break;
      }

      if(old_now <= 0) ang[0] = max(ang[0], abs(now));
    } else {
      now += g;

      if(now >= 360){
        flag = true;
        break;
      }

      if(old_now >= 0) ang[1] = max(ang[1], abs(now));
    }
  }

  if(flag || ang[0]+ang[1] >= 360) cout << "S\n";
  else cout << "N\n";

  return 0;
}
 
