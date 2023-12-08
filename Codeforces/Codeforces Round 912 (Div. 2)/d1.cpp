#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int MAX = ~0;

//O(1)
int bitCost(int& num, int bit){
  if(num & (1LL<<bit)) return 0;
  //numWithBit stores the first number greater than num that has the bit on
  int numWithBit= num;
  numWithBit |= (1LL<<bit);
  numWithBit &= (~((1LL<<bit)-1));
  int old_num = num;
  num = numWithBit;
  return numWithBit - old_num;
}

int sumCost(vector<int>& a, int bit){
  int sum = 0;
  int n = a.size();
  for(int i=0; i<n; i++){
    int individualCost = bitCost(a[i], bit);
    if(sum <= MAX - individualCost) sum += individualCost;
    else sum = MAX;
  }
  return sum;
}

void solve(){
  //Initialize
  int n;
  vector<int> a;
  cin >> n;
  int q; cin >> q;
  a.resize(n);
  for(int i=0; i<n; i++) cin >> a[i];
  
  vector<int> org = a;

  //Program
  while(q--){
    a = org;
    int k; cin >> k;
    int res = 0;
    vector<int> tmp;
    for(int i=63; i != MAX; i--){
      tmp = a;
      int costSumBit = sumCost(tmp, i);
      if(costSumBit <= k){
        k -= costSumBit;
        a = tmp;
        res |= (1LL<<i);
      }
    }
    cout << res << "\n";
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
