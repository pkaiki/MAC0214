#include <bits/stdc++.h>
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  string s; cin >> s;

  if(s[0] == '.'){
    cout << "-1\n";
    return 0;
  }

  int ans = 0, cont[2] = {1, 0};
  for(int i = 1; i < n; i++){
    if(s[i] == '.'){
      if(s[i-1] == 'x'){
        cont[1] = 0;
        ans++;
      }

      cont[1]++;

      if(cont[1] > cont[0]){
        cout << "-1\n";
        return 0;
      }
    } else {
      if(s[i-1] == '.')
        cont[0] = 0;

      cont[0]++;
    }
  }

  cout << ans << "\n";

  return 0;
}
 
