#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, x, acc = 0;
	cin >> n >> x;
	
	vector<ll> a(n);
	for(ll& i : a){
		cin >> i;
		acc += i*i;
	}

	long double aux = (long double)acc/n;

	long double r;
	if(acc == 0) r = 1;
	else if(x == 0) r = 0;
	else r = 1.0/sqrt((long double)aux/x);

	for(ll& i : a)
		cout << fixed << setprecision(8) << (long double) i*r << " ";
	cout << "\n";

	return 0;
}
 
