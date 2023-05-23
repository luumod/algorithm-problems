#include <bits/stdc++.h>

const int N=110;
void solve(){
	int n,m;
	std::cin>>n>>m;
	int sn=n*m;
	std::vector<int> vec(sn);
	for (auto& x:vec){
		std::cin>>x;
	}
	std::sort(vec.begin(),vec.end());
	int mx=vec[sn-1],sec_mx=vec[sn-2],mi=vec[0],sec_mi=vec[1];
	int ans=0;
	if (n<=m){
		//列长，行小
		ans=(mx-mi)*(sn-n);
		ans+=std::max(sec_mx-mi,mx-sec_mi)*(n-1);
	}
	else{
		//行长，列小
		ans=(mx-mi)*(sn-m);	
		ans+=std::max(sec_mx-mi,mx-sec_mi)*(m-1);
	}
	std::cout<<ans<<'\n';
}
int main(){
    int n;
    std::cin>>n;;
    while (n--){
        solve();
    }
	return 0;
}