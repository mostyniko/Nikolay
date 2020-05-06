/* Эта структура в решении задач из этого раздела не использовалась, но обладает многими приемуществами.
   1. Ctrl C + Ctrl V и ничего писать не надо.
   2. Удобный оператор (), который выделяет чистый хеш между прочим.
   3. Низкая вероятность коллизиии, из-за двух взаимно простых модулей эквивалентных одному 10^27.
   4. Устойчивость к анти-хеш тестам опять же из-за двойного модуля.
   
   Не забудьте:
   1) initialize() в начале программы, оно генерит множитель полинома и заполняет pow1 и pow2.
   2) отнимать числа по простому модуля формулой (a + mod - b) % mod.
   
   Вот пример заполнения хеша:
   { 0, s[0], s[0]*p + s[1], s[0]*p^2 + s[1] * p + s[2], ...}
*/

typedef long long ll;
const int maxLen = 200001;
struct PHash {
	static const ll mod = 1e9 + 321;
	static vector<ll> pow1, pow2;
	static ll base;
	int sz;
	vector<ll> h1, h2;
	
	PHash(const string& s) {
		sz = s.size();
		h1.resize(sz + 1); h2.resize(sz + 1);
		for(int i = 0; i < sz; i++) {
			h1[i+1] = (h1[i] * base + s[i]) % mod;
			h2[i+1] = h2[i] * base + s[i];
		}
	}
	
	pair<ll, ll> operator()(const int l, const int r) const {
		return {(h1[r+1] + mod - (h1[l] * pow1[r - l + 1]) % mod) % mod, h2[r+1] - h2[l] * pow2[r - l + 1]};
	}
};

void initialize() {
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 mt_rand(seed);
	PHash::base = uniform_int_distribution<ll>(257, PHash::mod)(mt_rand);
	
	for(int i = 1; i < maxLen; i++) {
		PHash::pow1[i] = (PHash::pow1[i-1] * PHash::base) % PHash::mod;
		PHash::pow2[i] = (PHash::pow2[i-1] * PHash::base);
	}
}

ll PHash::base = (ll)1e9+7;
vector<ll> PHash::pow1(maxLen, 1), PHash::pow2(maxLen, 1);

int main() {
	initialize();
}
