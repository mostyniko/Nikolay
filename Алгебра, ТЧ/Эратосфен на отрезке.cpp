// Eratosphene Sieve on segment
// segment left and right (<= 1e9) difference is less then 1e6.
// For 1e5 there are about 1e4 primes.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> p;
bool prime[1000000];

int main() {
	int q;
	cin >> q;
	vector<char> temp(100001, 1);
	temp[0] = temp[1] = false;
	for(ll i = 2; i <= 100000; i++) {
		if(temp[i]) {
			p.push_back(i);
			for(ll j = i*i; j < 100001; j += i) temp[j] = false;
		}
	}
	
	
	while(q--) {
		ll l, r;
		cin >> l >> r;
		for(int i = 0; i < 1000000; i++) prime[i] = true;
		if(l == 1) prime[0] = false;
		
		for(int i = 0; i < p.size(); i++) {
			ll left = (l / p[i]) * p[i];
			if(left < l) left += p[i];
			left = max(left, p[i]*2); // dont disable p[i].
			
			for(int j = left; j <= r; j += p[i]) {
				prime[j - l] = false; 
			}	
		}
		
		for(int i = l; i <= r; i++) cout << i << " prime: " << prime[i - l] << endl;
	}
}

/* 
*/
