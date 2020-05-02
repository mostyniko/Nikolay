#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll p = 31;
ll p_pow[200001];
set<ll> s;


int main() {
	p_pow[0] = 1;
	for(int i = 1; i <= 200000; i++) p_pow[i] = p * p_pow[i-1];
	
	string str;
	cin >> str;
	
	for(int i = 0; i < str.size(); i++) {
		ll cur_h = 0;
		for(int j = 0; j < str.size() - i; j++) {
			cur_h += (str[i+j] - 'a' + 1) * p_pow[j];
			s.insert(cur_h);
		}
	}
	
	cout << s.size() << endl;
}
