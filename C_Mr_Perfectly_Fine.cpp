#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::pair<int,std::string>> vec(n);
    for (auto& x:vec){
        std::cin>>x.first>>x.second;
    }
    std::sort(vec.begin(),vec.end());
    int ans=1e9,len=0;
    std::string s="11";
    std::string t="xx";
    for (auto& x:vec){
        if (x.second==s){
            t=s;
            len=x.first;
        }
        else if (t[0]=='x' && x.second[0]=='1'){
            t[0]='1';
            len+=x.first;
        }
        else if (t[1]=='x' && x.second[1]=='1'){
            t[1]='1';
            len+=x.first;
        }
        if (t==s){
            ans=std::min(ans,len);
            t="xx";
        }
    }
    if (ans==1e9){
        std::cout<<-1<<'\n';
        return;
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