#include <bits/stdc++.h>

void solve(){
    int n,st;
    std::cin>>n>>st;
    std::vector<int> vec;
    int cnt1=0,cnt2=0;
    for (int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        if (x==-1){
            cnt1++;
        }
        else if (x==-2){
            cnt2++;
        }
        else{
            vec.push_back(x);
        }
    }
    std::sort(vec.begin(),vec.end());
    vec.erase(std::unique(vec.begin(),vec.end()),vec.end());
    int ans=0;
    ans=std::max(ans,cnt1+(int)vec.size());
    ans=std::max(ans,cnt2+(int)vec.size());
    ans=std::min(ans,st);//不能超过总座位
    for (int i=0;i<vec.size();i++){
        int l=std::min(vec[i]-1,i+cnt1);
        int r=std::min(st-vec[i],int(vec.size())-1-i+cnt2);
        ans=std::max(ans,l+1+r);
    }
    std::cout<<ans<<'\n';
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
	return 0;
}