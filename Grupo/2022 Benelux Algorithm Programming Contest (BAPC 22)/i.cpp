#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef long double ld;

typedef struct edge {
	int b;
	ld c;
	bool i;
} edge;

typedef struct step {
	int p;
	int b;
	ld c;
} step;

int geti(int& ci, unordered_map<string, int>& is) {
	char c;
	string s;
	s.reserve(40);
	while((c = getchar()) != ' ' && c != '\n')
		s.push_back(c);
	auto p = is.find(s);
	//printf("read "); for(char cc : s) putchar(cc); putchar('\n'); //DD
	if(p != is.end()) 
		return (*p).second;	
	is[s] = ci;
	//printf("created %d\n", ci); //DD
	return ci++;
}

void esc() {
	char c = getchar();
	//printf("escaping "); putchar(c); //DD
	while(c != ' ' && c != '\n') {
		c = getchar();
		//putchar(c); //DD
	}
	//putchar('\n'); //DD
}

int main() {
	int ci = 0;
	unordered_map<string, int> is;
	vector<vector<edge>> es(200);

	int qe, qq; scanf("%d %d\n", &qe, &qq);

	for(int i=0; i<qe; i++) {
		int ai, bi;
		ld c;
		esc();	
		ai = geti(ci, is);
		esc();
		scanf("%Lf ", &c);
		bi = geti(ci, is);
		es[ai].push_back({bi, c, false});
		es[bi].push_back({ai, c, true});
	}

	vector<int> vs(200, -1);
	for(int i=0; i<qq; i++) {
		int si, ti;
		ld sc, rc = -10;
		vector<step> fs, bs;
		scanf("%Lf ", &sc);
		si = geti(ci, is);
		esc();
		ti = geti(ci, is);
		fs.push_back({-1, si, sc}); 
		vs[si] = i;
		//printf("going to go si:%d ti:%d sc:%Lf\n", si, ti, sc); //DD
		while(!fs.empty()) {
			while(!fs.empty()) {
				step s = fs.back(); fs.pop_back();
				int a = s.b, p = s.p;
				ld c = s.c;
				if(a == ti) {
					rc = c;
					break;
				}
				for(edge e : es[a]) if(vs[e.b] != i) {
					if(e.i)
						bs.push_back({a, e.b, c/e.c});
					else
						bs.push_back({a, e.b, c*e.c});
					vs[e.b] = i;
				}
			}
			swap(fs, bs);
		}
		if(rc < -5) puts("impossible");
		else printf("%.20Le\n", rc);
	}

	return 0;
}
