#include<bits/stdc++.h>
#define int long long
using namespace std;

/* plan:
- sieve
- factor
- list possible primes
- put all possible strings in map (first singer)
- check all possible strings of second singer
  - there is no unknown prime
  - freqs match
*/

const int MAXN = 1e9+1000;

vector<int> primes;

void sieve(int n){
  vector<bool> ip(n+1, true);
  ip[0] = false;
  ip[1] = false;
  for(int i=2; i<=n; i++) if(ip[i]) { 
    primes.push_back(i);
    for(int p=i; p<=n; p+=i)
      ip[p] = false;
  }
}

set<int> st;
vector<int> used_primes;
map<int, int> find_index;
vector<pair<int,int>> factors_of_a[16];
vector<pair<int,int>> factors_of_b[16];

void factor_a(int x, int i){
  for(auto p : primes){
    if(p*p > x) break;
    if(x%p == 0){
      st.insert(p);
      int cnt = 0;
      while(x%p == 0){
        x /= p;
        cnt++;
      }
      factors_of_a[i].push_back({p, cnt});
    }
  }
  if(x != 1){
    st.insert(x);
    factors_of_a[i].push_back({x, 1});
  }
}

unordered_map<string, int> get_bitmask;

void factor_b(int x, int i){
  for(auto p : primes){
    if(p*p > x) break;
    if(x%p == 0){
      int cnt = 0;
      while(x%p == 0){
        x /= p;
        cnt++;
      }
      factors_of_b[i].push_back({p, cnt});
    }
  }
  if(x != 1){
    factors_of_b[i].push_back({x, 1});
  }
}

void add_a(int i, string& s){
  for(auto [p, cnt] : factors_of_a[i]){
    int index = find_index[p];
    int plus = max(s[2*index] + cnt - 255, (int)0);
    if(plus > 0){
      s[2*index-1] = plus;
      s[2*index] = 255;
    } 
    else s[2*index] += cnt;
 
  }
}

void check_b(int i, string& s){
  for(auto [p, cnt] : factors_of_b[i]){
    int index = find_index[p];
    if(index == 0){
      s = "";
      return;
    }
    int plus = max(s[2*index] + cnt - 255, (int)0);
    if(plus > 0){
      s[2*index-1] = plus;
      s[2*index] = 255;
    } 
    else s[2*index] += cnt;
  }
}

void solve(){
  //Declarando
  unordered_map<string, bool> mp;
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);

  //Crivo
  sieve(sqrt(MAXN)+1);

  //Criando o vetor de primos usados e os indices deles
  for(int i=0; i<n; i++){
    cin >> a[i];
    factor_a(a[i], i);
  }
  for(int i=0; i<m; i++){
    cin >> b[i];
    factor_b(b[i], i);
  }
  used_primes.push_back(-1);
  for(auto p : st){
    find_index[p] = used_primes.size();
    used_primes.push_back(p);
  }
  
  //Listando todas as possiveis strings para o primeiro cantor
  for(int bitmask = 1; bitmask < (1 << n); bitmask++){
    string s;
    for(int j=0; j<2*used_primes.size(); j++) s.push_back(0);
    for(int i=0; i<n; i++){
      if(bitmask & (1 << i)){
        add_a(i, s);
      }
    }
    get_bitmask[s] = bitmask;
    mp[s] = true;
  }

  //Listando todas as possiveis strings para o segundo cantor
  for(int bitmask = 1; bitmask < (1 << m); bitmask++){
    string s;
    for(int j=0; j<2*used_primes.size(); j++) s.push_back(0);
    for(int i=0; i<m; i++){
      if(bitmask & (1 << i)){
        check_b(i, s);
      }
    }
    if(mp[s]){
      cout << "Y\n";
      vector<int> res_a;
      vector<int> res_b;
      if(s == "") continue;
      int bitmask_a = get_bitmask[s];
      for(int i=0; i<n; i++)
        if(bitmask_a & (1<<i)) res_a.push_back(a[i]);

      for(int i=0; i<m; i++)
        if(bitmask & (1<<i)) res_b.push_back(b[i]);

      cout << res_a.size() << ' ' << res_b.size() << '\n';
      for(auto aa : res_a) cout << aa << ' '; cout << '\n';
      for(auto bb : res_b) cout << bb << ' '; cout << '\n';


      return;
    }
  }
  
  cout << "N\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
