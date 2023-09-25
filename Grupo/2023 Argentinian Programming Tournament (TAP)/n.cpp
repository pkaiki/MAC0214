#include <bits/stdc++.h>
#define int long long
using namespace std;

int cong[4];
void solve(){
	int n; cin >> n;
	int sum = 0;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		if(x%5 == 0) sum++;
		else cong[x%5]++;
	}

	int sub;

	sub = min(cong[1], cong[4]);
	sum += sub;
	cong[1] -= sub;
	cong[4] -= sub;

	sub = min(cong[2], cong[3]);
	sum += sub;
	cong[2] -= sub;
	cong[3] -= sub;

	int qnt = 0;
	for(int i=1; i<5; i++){
		if(cong[i] != 0) qnt++;
	}

	if(qnt == 0){
		cout << sum << '\n';
		return;
	}

	if(qnt == 1){
		for(int i=1; i<5; i++){
			sum += cong[i]/5;
		}
		cout << sum << '\n';
		return;
	}

	int A = 0, B = 0;
	if(cong[2] != 0 && cong[1] != 0) A = cong[2], B = cong[1];
	if(cong[1] != 0 && cong[3] != 0) A = cong[1], B = cong[3];
	if(cong[4] != 0 && cong[2] != 0) A = cong[4], B = cong[2];
	if(cong[3] != 0 && cong[4] != 0) A = cong[3], B = cong[4];
	
	int tirar = min(A/2, B);
	sum += tirar;
	A -= 2*tirar;
	B -= tirar;

	int tirar2 = min(A, B/3);
	sum += tirar2;
	A -= tirar2;
	B -= 3*tirar2;

	sum += A/5;
	sum += B/5;

	cout << sum << '\n';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}
