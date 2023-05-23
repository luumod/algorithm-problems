#include <bits/stdc++.h>

const int N=1010;
int main(){
	int n,m;
	std::cin>>n>>m;
	std::vector<int> in(n+1),vec[N],dis(n+1);
	for (int i=1;i<=m;i++){
		int sum=0;
		std::cin>>sum;
		while (sum--){
			int to;
			std::cin>>to;
			vec[i].push_back(to);
		}
		in[sum]++;
	}
	std::function<void(int)> topo=[&](int now){
		std::queue<int> q;
		for (int i=1;i<=n;i++){

		}

	};
	int ans=0;
	for (int i=1;i<=n;i++){
		ans=std::max(ans,dis[i]);
	}
	std::cout<<ans;
	return 0;
}