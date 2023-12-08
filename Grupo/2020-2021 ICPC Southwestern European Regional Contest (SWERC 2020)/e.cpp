#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  int ans = INF;

  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    ans = min(ans, b/a);
  }

  cout << ans << "\n";

  return 0;
}

