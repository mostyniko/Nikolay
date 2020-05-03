/* Double polynomial hash structure.
	DONT FORGET TO: 
	1. _hash::base = generate();
	2. after every string update, update also POW.
	3. operator(int l, int r, int POW).
*/



typedef unsigned long long ull;
struct _hash {
	static const ull mod = 1e9+123;
	static ull base;
	static vector<int> pow1;
	static vector<ull> pow2;
	
	
	vector<int> pref1;
	vector<ull> pref2;
	
	_hash(const string& s) {
		while(pow1.size() < s.size() + 1) pow1.push_back((1LL * pow1.back() * base) % mod);
		while(pow2.size() < s.size() + 1) pow2.push_back(pow2.back() * base);
		
		pref1.resize(s.size());
		pref2.resize(s.size());
		
		for(int i = 0; i < s.size(); i++) {
			pref1[i] = ((s[i] + 1LL) * pow1[i]) % mod;
			pref2[i] = (s[i] + 1LL) * pow2[i];
			
			if(i) {
				pref1[i] += pref1[i-1];
				pref2[i] += pref2[i-1];
				pref1[i] %= mod;
			}
		}
	}
	
	
	pair<int, ull> operator()(const int l, const int r, const int POW) const {
		int h1 = pref1[r];
		if(l) h1 -= pref1[l-1];
		if(h1 < 0) h1 += mod;
		ull h2 = pref2[r];
		if(l) h2 -= pref2[l-1];
		
		return { (1LL * h1 * pow1[POW - l]) % mod, h2 * pow2[POW - l]};	
	}
	
	void operator+=(const string& s) {
		int needed_pow = s.size() + pref1.size() + 1;
		while(pow1.size() < needed_pow) pow1.push_back((1LL * pow1.back() * base) % mod);
		while(pow2.size() < needed_pow) pow2.push_back(pow2.back() * base);
		
		for(int i = 0; i < s.size(); i++) {
			pref1.push_back(((s[i] + 1LL) * pow1[pref1.size()]) % mod);
			pref2.push_back((s[i] + 1LL) * pow2[pref2.size()]);
			
			if(pref1.size() > 1) {
				pref1[pref1.size() - 1] += pref1[pref1.size() - 2];
				pref2[pref2.size() - 1] += pref2[pref2.size() - 2];
				pref1[pref1.size() - 1] %= mod;
			}
		}
	}
};

vector<int> _hash::pow1{1};
vector<ull> _hash::pow2{1};

ull generate() {
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 mt_rand(seed);
	int x = uniform_int_distribution<ull>(257, _hash::mod)(mt_rand);
	return (x%2)? x : x-1;
}
ull _hash::base = (ull)1e9+7;
int POW = 0;


