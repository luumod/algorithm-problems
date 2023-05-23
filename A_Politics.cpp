#include <bits/stdc++.h>

void solve(){
	int n,k;
	std::cin>>n>>k;
	std::vector<std::string> vec(n+1);
	for (int i=1;i<=n;i++){
		std::string t;
		std::cin>>t;
		vec[i]=t;
	}
	int ans=1;
	std::vector<bool> vis(n+1,0);
	for (int z=0;z<k;z++){
		for (int i=2;i<=n;i++){
			if (!vis[i] && vec[i][z]!=vec[1][z]){
				vis[i]=true;
			}
		}
	}
	for (int i=2;i<=n;i++){
		ans+=(vis[i]==false);
	}
	std::cout<<ans<<'\n';
}
int main(){
	int n;
	std::cin>>n;
	while (n--){
		solve();
	}
	return 0;
}