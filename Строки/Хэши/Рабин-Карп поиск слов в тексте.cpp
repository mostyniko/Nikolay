
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll p = 101;
ll p_pow[200001];
ll h[200001];
ll h_s;

int main() {
	p_pow[0] = 1;
	for(int i = 1; i <= 200000; i++) p_pow[i] = p_pow[i-1] * p;
	
	string t; string s;
	getline(cin, t);
	
	h[0] = t[0] - 'a' + 1;
	for(int i = 1; i < t.size(); i++) {
		h[i] = h[i-1] + (t[i] - 'a' + 1) * p_pow[i];
	}
	
	while(true) {
		cin >> s;
		if(s == "#") return 0; 
		
		h_s = 0;
		for(int i = 0; i < s.size(); i++) {
			h_s += (s[i] - 'a' + 1) * p_pow[i];
		}
		
		for(int st = 0; st + s.size() - 1 < t.size(); st++) {
			ll cur_h = h[st+s.size() - 1];
			if(st) cur_h -= h[st-1];
			if(h_s * p_pow[st] == cur_h) cout << st << " ";
		}
		cout << endl;
	}
}

