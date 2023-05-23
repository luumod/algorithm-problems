#include <bits/stdc++.h>

#define int long long
std::set<int> st;
void solve(){
	int n;
	std::cin>>n;
	if (n&(n-1)){ 
		std::cout<<"YES\n";
	}
	else{ //n&(n-1) 一定是2的幂
		std::cout<<"NO\n";
	}
}
signed main(){
	signed n;
	std::cin>>n;
	while (n--){
		solve();	
	}
	return 0;
}