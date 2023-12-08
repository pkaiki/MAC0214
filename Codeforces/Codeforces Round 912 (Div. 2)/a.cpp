#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    if(k == 1){
        for(int i=1; i<n; i++){
            if(v[i] < v[i-1]){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    if(k > 1){
        cout << "YES\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
