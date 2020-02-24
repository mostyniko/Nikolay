#include <bits/stdc++.h>
using namespace std;

struct node {
	int y, value, cnt;
	node *l, *r;
	
	node(int value): value(value), y(rand()), cnt(1), l(nullptr), r(nullptr)
	{}
};

int cnt(node*& t) {
	return t? t->cnt : 0;
}

void upd_cnt(node*& t) {
	if(!t) return;
	t->cnt = cnt(t->l) + cnt(t->r) + 1;
}

pair<node*, node*> split(node*& t, int key) {
	if(!t) return {nullptr, nullptr};
	
	int cur_key = cnt(t->l);
	if(cur_key < key) {
		auto res = split(t->r, key - cur_key - 1);
		t->r = res.first;
		upd_cnt(t);
		return {t, res.second};
	} else {
		auto res = split(t->l, key);
		t->l = res.second;
		upd_cnt(t);
		return {res.first, t};
	}
}

node* merge(node* l, node* r) {
	if(!l || !r) return l? l : r;
	
	if(l->y > r->y) {
		l->r = merge(l->r, r);
		upd_cnt(l);
		return l;
	} else {
		r->l = merge(l, r->l);
		upd_cnt(r);
		return r;
	}
}

void insert(node*& t, int key, node*& element) {
	auto res = split(t, key);
	t = merge(merge(res.first, element), res.second);
	upd_cnt(t);
}

void erase(node*& t, int key) {
	auto res1 = split(t, key);
	auto res2 = split(res1.second, 1);
	
	t = merge(res1.first, res2.second);
	upd_cnt(t);
}

int find(node* t, int key) {
	if(!t) return -1;
	
	int cur_key = cnt(t->l);
	if(key == cur_key) return t->value;
	if(cur_key < key) return find(t->r, key - cur_key - 1);
	else return find(t->l, key);
}

void print(node* t) {
	if(!t) return;
	
	print(t->l);
	cout << t->value << " ";
	print(t->r); 
}

int main() {
	node* root = nullptr;
	
	for(int i = 0; i <= 10; i++) {
		node* n = new node(0);
		insert(root, 0, n);
	}
	
	
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int type;
		cin >> type;
		
		if(type == 1) {
			int idx, val;
			cin >> idx >> val;
			node* n = new node(val);
			erase(root, idx);
			insert(root, idx, n);
		}
		
		if(type == 2) {
			int idx;
			cin >> idx;
			erase(root, idx);
		}
		
		if(type == 3) {
			print(root); cout << endl;
		}
	}
 	
}
