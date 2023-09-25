#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

map<string, long double> coords;

int main(){
	coords["N"] = 0.0;
	coords["NE"] = 45.0;
	coords["E"] = 90.0;
	coords["SE"] = 135.0;
	coords["S"] = 180.0;
	coords["SW"] = 225.0;
	coords["W"] = 270.0;
	coords["NW"] = 315.0;

	string dir[2]; cin >> dir[0] >> dir[1];
	long double degree[2];

	for(int i = 0; i < 2; i++){
		if(dir[i].size() == 1){
			degree[i] = coords[dir[i]];
			continue;
		}
		
		string align = dir[i].substr(dir[i].size()-2);

		degree[i] = coords[align];

		long double p = 45.0/2.0;

		map<char, int> sign;
		if(align == "NE") sign['N'] = -1, sign['E'] = 1;
		else if(align == "SE") sign['E'] = -1, sign['S'] = 1;
		else if(align == "SW") sign['S'] = -1, sign['W'] = 1;
		else sign['W'] = -1, sign['N'] = 1;

		for(int j = 3; j < 30 && (int)dir[i].size() - j >= 0; j++){
			char c = dir[i][dir[i].size() - j];

			degree[i] += (long double) sign[c]*p;

			p /= 2.0;
		}
	}

	if(degree[0] - degree[1] > EPS) swap(degree[0], degree[1]);

	cout << fixed << setprecision(10) <<
		min(degree[1] - degree[0], 360.0 - degree[1] + degree[0]) << "\n";

	return 0;
}
 
