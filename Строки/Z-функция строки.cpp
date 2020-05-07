// z-func

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; int n;
	cin >> s; n = s.size();
	vector<int> z(n);
	
	for(int i = 1, l = 0, r = 0; i < n; i++) {
		if(i > r) {
			int k = 0, cur = i;
			while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		}
		
		if(i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
			while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		}
		
		if(i + z[i] - 1 > r) {
			l = i; r = i + z[i] - 1;
		}
	}
	
	for(int i = 0; i < n; i++) cout << "z[" << i << "] = " << z[i] << endl;
}
