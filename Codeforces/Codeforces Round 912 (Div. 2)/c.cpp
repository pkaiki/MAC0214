#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> acc(n+1, 0);
    vector<int> res(n+1, 0);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=n-1; i>=0; i--) acc[i] = acc[i+1] + a[i];
    res[0] = max(a[0], acc[0]);
    for(int i=1; i<n; i++){
        res[i] = res[i-1] + max(a[i], acc[i]);
    }
    cout << res[n-1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
