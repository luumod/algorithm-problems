#include <bits/stdc++.h>

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::string s;
    std::cin>>s;
    std::vector<int> lo(26,0),hi(26,0);
    for (auto &x:s){
        if (std::islower(x)){
            lo[x-'a']++;
        }
        else{
            hi[x-'A']++;
        }
    }   
    int ans=0,mx=0;
    for (int i=0;i<26;i++){
        int num=std::min(lo[i],hi[i]);//正常配对可以得到ans个
        lo[i]-=num,hi[i]-=num;
        ans+=num;
        //mx+=(lo[i]+hi[i])/2;//完美配对可以得到mx个
        mx+=abs(lo[i]+hi[i])/2; //经过操作后产生的新配对
    } 
    ans+=std::min(k,mx); 
    //ans=std::min(ans+k,mx); //每一次k都是一个使完美的配对，最多操作k次
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