#include <bits/stdc++.h>
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  string s, t; cin >> s >> t;

  int shift = 0, ans = 0;

  for(int i = 0; i < n; i++){
    char aux = (((s[i]-'a') + shift) % 26) + 'a';

    if(aux == t[i]) continue;
    else{
      if(t[i] >= s[i])
        shift = t[i]-s[i];
      else
        shift = 26-(s[i]-'a')+(t[i]-'a');
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}
