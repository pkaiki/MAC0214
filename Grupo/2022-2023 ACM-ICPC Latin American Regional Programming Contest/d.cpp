#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n, h, w; cin >> n >> h >> w;

  for(int i=0; i<n; i++){
    char ida; cin >> ida;
    if(ida == 'Y'){
      h--;
      w++;
      cout << "Y ";
    }
    else{
      if(w == 0){
        h--;
        w++;
        cout << "Y ";
      }
      else cout << "N ";
    }

    char volta; cin >> volta;
    if(volta == 'Y'){
      w--;
      h++;
      cout << "Y\n";
    }
    else{
      if(h == 0){
        w--;
        h++;
        cout << "Y\n";
      }
      else cout << "N\n";
    }



  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
 
