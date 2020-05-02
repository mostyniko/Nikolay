
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll p = 31;
ll p_pow[200001];
ll h_s[200001];
ll h_t[200001];
string s, t; int latest;

bool possible(int len) {
	set<ll> s_substr;
	
	int res_pow = max(s.size(), t.size());
	for(int i = 0; i < s.size() - len + 1; i++) {
		ll cur_h = h_s[i + len - 1];
		if(i) cur_h -= h_s[i-1];
		cur_h *= p_pow[res_pow - i];
		s_substr.insert(cur_h);
	}
	
	bool flag = false;

	for(int i = 0; i < t.size() - len + 1; i++) {
		ll cur_h = h_t[i + len - 1];
		if(i) cur_h -= h_t[i-1];
		cur_h *= p_pow[res_pow - i];
		if(s_substr.find(cur_h) != s_substr.end()) {
			latest = i;
			flag = true;
			break;
		}
	}
	
	return flag;
}

int main() {
	cin >> s >> t;
	
	p_pow[0] = 1;
	for(int i = 1; i <= 200000; i++) p_pow[i] = p_pow[i-1] * p;
	
	h_s[0] = s[0] - 'a' + 1;
	for(int i = 1; i < s.size(); i++) h_s[i] = h_s[i-1] + (s[i] - 'a' + 1) * p_pow[i];
	h_t[0] = t[0] - 'a' + 1;
	for(int i = 1; i < t.size(); i++) h_t[i] = h_t[i-1] + (t[i] - 'a' + 1) * p_pow[i];
	
	int l = 0;
	int r = min(s.size(), t.size()) + 1;
	while(r - l > 1) {
		int m = (r + l) / 2;
		if(possible(m)) l = m;
		else r = m;
	}
	
	for(int i = latest; i < latest + l; i++) cout << t[i];
}


