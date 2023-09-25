#include <bits/stdc++.h>
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k; cin >> n >> m >> k;

  if(m == 0){ // sem matching
    if(n > 26) cout << "No\n";
    else {
      cout << "Yes\n";
      for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++)
          cout << (char)('a'+i);
        cout << "\n";
      }
    }
  
    return 0;
  }

  if(k == 1 || m >= k){ // se k == 1, então m == 0 (caiu antes) ou m == 1 (impossível)
    cout << "No\n";
    return 0;
  }

  cout << "Yes\n";

  // cozinhando o match
  for(int i = 0; i < k; i++)
    cout << 'y';
  cout << '\n';

  for(int i = 0; i < m; i++)
    cout << 'y';
  for(int i = m; i < k; i++)
    cout << 'z';
  cout << '\n';

  // printando os outros casos pra bater n
  int cont = 2;
  for(char i = 'a'; i <= 'z' && cont < n; i++){
    for(char j = i+1; j <= 'z' && cont < n; j++, cont++){
      assert(!(i == 'y' && j == 'z'));

      for(int p = 0; p < k; p++){
        if(p&1) cout << i;
        else cout << j;
      }
      cout << "\n";
    }
  }

  return 0;
}
