#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll p = 31;
ll p_pow[200001];
ll Hash[200001], reverse_hash[200001];
string s;

ll BinSearch(ll c, ll shift) {
	ll l = 0, r = min(c + 1, s.size() - c - shift + 1);
	while(r - l > 1) {
		ll m = (l + r) / 2;
		int l1 = c - m, r1 = c-1;
		int l2 = c + shift, r2 = l2 + m - 1;
		ll h1 = Hash[r1] - Hash[l1 - 1];
		ll h2 = reverse_hash[l2] - reverse_hash[r2 + 1];
		
		h1 *= p_pow[s.size() - l1];
		h2 *= p_pow[s.size() - (s.size() - r2 - 1)];
		
		
		if(h1 == h2) l = m;
		else r = m;
	}
	
	return l;
}

int main() {
	p_pow[0] = 1;
	for(int i = 1; i <= 200000; i++) p_pow[i] = p * p_pow[i-1];
	
	cin >> s;
	
	Hash[0] = s[0] - 'a' + 1;
	for(int i = 1; i < s.size(); i++) {
		Hash[i] = Hash[i-1] + (s[i] - 'a' + 1) * p_pow[i];
	}
	
	reverse_hash[s.size() - 1] = s[s.size() - 1] - 'a' + 1;
	for(int i = s.size() - 2; i >= 0; i--) {
		reverse_hash[i] = reverse_hash[i+1] + (s[i] - 'a' + 1) * p_pow[s.size() - 1 - i];
	}
	
	ll ans = 0;
	for(int center = 0; center < s.size(); center++) {
		ans += BinSearch(center, 0) + BinSearch(center, 1) + 1;
	}
	
	cout << ans << endl;
}
