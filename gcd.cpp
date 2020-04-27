#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return a? gcd(b % a, a) : b;
}

// ABAAB rule.
