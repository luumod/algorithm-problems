#include <bits/stdc++.h>

const int N=210;
void solve(){
	int n,m;
	std::cin>>n>>m;
	std::vector<int> vec[N];
	for (int i=1;i<=m;i++){
		int y,x;
		std::cin>>y>>x;
		vec[y].push_back(x);
		vec[x].push_back(y);
	}
	int yy=0;
	for (int i=1;i<=n;i++){
		yy+=(vec[i].size()==1);
	}
	int cx=n-yy;
	cx-=1;
	int cy=yy/cx;
	std::cout<<cx<<' '<<cy<<'\n';
}
int main(){
	int n;
	std::cin>>n;
	while (n--){
		solve();
	}
	return 0;
}