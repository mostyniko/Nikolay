#include <bits/stdc++.h>
#include <conio.h>
#define mp make_pair
using namespace std;

const int sz = 2e5 + 2;
pair<int, int> p[sz];
int r[sz];

void init() {
	for(int i = 1; i < sz; i++) {
		r[i] = 1; p[i] = mp(i, 0);
	}
}

pair<int, int> find_set(int x) {
	if(x == p[x].first) return mp(x, 0);
	int temp = p[x].second;
	p[x] = find_set(p[x].first);
	p[x].second += temp;
	return p[x]; 
}

void union_sets(int a, int b) {
	a = find_set(a).first; b = find_set(b).first;
	if(a == b) return;
	if(r[a] > r[b]) swap(a, b);
	p[a] = mp(b, 1);
	r[b] += r[a]; 
}

int main() {
	int n, q;
	cin >> n >> q;
	init();
	while(q--) {
		system("CLS");
		cout << "Press \"m\" to merge, \"d\" to display depth\n";
		char ch;
		ch = getch();
		
		if(ch == 'm') {
			cout << "a, b: ";
			int a, b;
			cin >> a >> b;
			union_sets(a, b);
		}
		
		if(ch == 'd') {
			cout << "a: ";
			int a; cin >> a;
			cout << find_set(a).second << endl;	
		}
		
		system("pause");
	}
}
