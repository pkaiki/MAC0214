#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;
    int M[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> M[i][j];
        }
    }
    if(n == 1){
        cout << "YES\n";
        cout << "7\n";
        return;
    }

    //Code here
    vector<int> a(n);

    for(int i=0; i<n; i++){
        a[i] = (1<<30)-1;
    }

    for(int k=0; k<30; k++){
         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((M[i][j] & (1<<k)) == 0){
                    int mask = ~(1<<k);
                    a[i] &= mask;
                }
            }
        }

         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(((~M[i][j]) & (1<<k)) and ((a[i] | a[j]) & (1<<k))){
                    if((~a[i]) & (1<<k)){
                        int mask = ~(1<<k);
                        a[j] &= mask;
                    }
                    else{
                        int mask = ~(1<<k);
                        a[i] &= mask;
                    }
                }
            }
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(M[i][j] != (a[i] | a[j])){
                cout << "NO\n";
                return;
            }       
        }
    }
    cout << "YES\n";
    for(auto x : a) cout << x << ' '; cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
