#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e5+10;
int n,m;
std::string s;
void solve(){
    std::cin>>n;
    std::cin>>s;
    int ans=0;
    std::set<std::pair<int,int>> ust;
    for (int i=0;i<s.size()-1;i++){
        ust.insert({s[i],s[i+1]});
    }
    std::cout<<ust.size()<<'\n';
}
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}