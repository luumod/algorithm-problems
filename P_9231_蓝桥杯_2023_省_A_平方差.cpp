#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;
int f(int x) {
	if (!x) return 0;
	return (x + 1) / 2;
}
int g(int x) {
	return x / 4;
}
int main() {
	int l, r; 
    std::cin >> l >> r;
	std::cout << f(r) - f(l - 1) + g(r) - g(l - 1);
    return 0;
}