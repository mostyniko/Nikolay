// trie

#include <bits/stdc++.h>
using namespace std;

struct vertex {
	int next[26];
	int cnt;
	
	vertex() {
		for(int i = 0; i < 26; i++) next[i] = 0;
		cnt = 0;
	}
};

int c = 1;
vertex v[100000];

void add(string& s) {
	int cur_v = 1;
	for(int i = 0; i < s.size(); i++) {
		int point = s[i] - 97;
		if(!v[cur_v].next[point]) v[cur_v].next[point] = ++c;
		cur_v = v[cur_v].next[point];
	}
	
	v[cur_v].cnt++;
}

string s = "";
void showTrie(int cur_v = 1) {
	for(int i = 0; i < v[cur_v].cnt; i++) cout << s << endl;
	for(int i = 0; i < 26; i++) {
		if(v[cur_v].next[i]) {
			s += char(i + 97);
			showTrie(v[cur_v].next[i]); 
			s.erase(s.size() - 1, 1);
		}
	}
}

int main() {
 	int q;
 	cin >> q;
 	for(int i = 0; i < q; i++) {
 		string str;
 		cin >> str;
 		add(str);
	 }
	 
	 showTrie(1);
}
