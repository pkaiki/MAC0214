#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	char carpet[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> carpet[i][j];
		}
	}

	string vika = "vikaa";
	int it = 0;#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	char carpet[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> carpet[i][j];
		}
	}

	string vika = "vikaa";
	int it = 0;

	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			if(vika[it] == carpet[i][j]){
				i=n;
				it++;
			}
			if(it == vika.size()-1){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
	return;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) solve();
}

	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			if(vika[it] == carpet[i][j]){
				i=n;
				it++;
			}
			if(it == vika.size()-1){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
	return;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) solve();
}
