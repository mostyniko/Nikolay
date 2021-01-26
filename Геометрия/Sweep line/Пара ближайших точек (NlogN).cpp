#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define double long double
#define int long long
using namespace std;
using namespace __gnu_pbds;


struct point {
	double x, y, id;
	
	point(int X = 0, int Y = 0, int ID = 0) {
		x = X; y = Y; id = ID;
	}
};

bool operator<(const point& a, const point& b) {
		if(a.y != b.y) return a.y < b.y;
		else return a.x < b.x;
}


typedef tree <
point,
null_type,
less<point>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int n;
vector<point> v;
ordered_set s;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	v.resize(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
		v[i].id = i;
	}
	
	sort(v.begin(), v.end(), [](const point& a, const point& b) {
		return a.x < b.x;
	});
	
	double h = 1e18+7;
	int a, b;
	
	for(int i = 0; i < n; i++) {
		vector<ordered_set::iterator> del;
		for(int j = s.order_of_key(point(-1, v[i].y-sqrt(h))); j < s.order_of_key(point(1e13, v[i].y+sqrt(h))); j++) {
			point c = *s.find_by_order(j);
			double dist = (v[i].x - c.x)*(v[i].x - c.x) + (v[i].y - c.y)*(v[i].y - c.y);
			if(v[i].x - c.x > sqrt(h)) del.push_back(s.find_by_order(j));
			if(h > dist) {
				a = c.id;
				b = v[i].id;
				h = dist;
			}
		} 
		for(int j = 0; j < del.size(); j++) s.erase(del[j]);
		s.insert(v[i]);
	}
	
	if(a > b) swap(a, b);
	cout << a << " " << b << " ";
	cout << setiosflags(ios::fixed) << setprecision(6) << sqrt(h) << endl;
}

