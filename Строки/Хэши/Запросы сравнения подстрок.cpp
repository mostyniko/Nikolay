#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll p = 31;
ll p_pow[200001];
ll h[200001];

int main() {
	p_pow[0] = 1;
	for(int i = 1; i <= 200000; i++) p_pow[i] = p_pow[i-1] * p;	
	
	string s;
	ll i1, i2, len;
	cin >> s >> i1 >> i2 >> len;
	
	h[0] = s[0] - 'a' + 1;
	for(int i = 1; i < s.size(); i++) {
		h[i] = (s[i] - 'a' + 1)*p_pow[i] + h[i-1];
	}
	
	ll h1 = h[i1 + len - 1] - h[i1-1], h2 = h[i2 + len - 1] - h[i2-1];
	
	if((i1 < i2 && h1 * p_pow[i2-i1] == h2) ||
	(i1 > i2 && h2 * p_pow[i1-i2] == h1) || i1 == i2) cout << "Equal";
	else cout << "Not equal";
}
