#include <bits/stdc++.h>
#if 1
    #define int long long
#endif
using ll=long long;

const int N=1e5+10;
int n,m,k,ans;
std::string s;
char a,b;
signed main(){
    std::cin>>k;
    std::cin>>s>>a>>b;
    n=s.size();
    std::vector<int> pbeg,pend;
    for (int l=0;l<n;l++){
        if (s[l]==a){
            pbeg.push_back(l);
        }
        if (s[l]==b){
            pend.push_back(l);
        }
    }
    for (auto& x:pbeg){
        int y=x+k-1; //最小的
        int nums=pend.end()-std::lower_bound(pend.begin(),pend.end(),y);
        ans+=nums;
    }
    std::cout<<ans;

    return 0;
}