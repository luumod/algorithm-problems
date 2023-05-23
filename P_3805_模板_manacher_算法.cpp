#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;
#define io std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
template <typename T1=int,typename T2=int>
using ump=std::unordered_map<T1,T2>;
template <typename T=int>
using ust=std::unordered_set<T>;

const int N=3e7+10;
int n,m;
std::string s,rs;
int d[N];
int ans=1;
void init(){
    rs+="$#";
    for (int i=0;i<s.size();i++){
        rs+=s[i];
        rs+='#';
    }
    n=rs.size();
}
void get_d(){
    d[1]=1;
    for (int i=2,l,r=1;i<=n;i++){
        if (i<=r){
            d[i]=std::min(d[r-i+l],r-i+1);
        }
        while (rs[i-d[i]]==rs[i+d[i]]){
            d[i]++;
        }
        if (i+d[i]-1>r){
            l=i-d[i]+1,r=i+d[i]-1;
        }
        ans=std::max(ans,d[i]-1);
    }
}
signed main(){
    std::cin>>s;
    init();
    get_d();
    std::cout<<ans;
    return 0;
}