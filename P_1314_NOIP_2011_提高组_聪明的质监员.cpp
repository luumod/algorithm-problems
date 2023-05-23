#include <bits/stdc++.h>
using ll=long long;
int main(){
    ll n,m,s;
    std::cin>>n>>m>>s;
    std::vector<ll> ws(n+1),vs(n+1),wn(n+1),vn(n+1),ln(m+1),rn(m+1);
    for (int i=1;i<=n;i++){
        std::cin>>ws[i]>>vs[i];
    }
    ll res=1e12;
    auto check=[&](int w){
        std::fill(vn.begin(),vn.end(),0);
        std::fill(wn.begin(),wn.end(),0);
        for (int i=1;i<=n;i++){
            if (ws[i]>=w){
                wn[i]=wn[i-1]+1;
                vn[i]=vn[i-1]+vs[i];
            }
            else{
                wn[i]=wn[i-1];
                vn[i]=vn[i-1];
            }
        }
        //计算m个区间校验和
        ll ans=0;
        for (int i=1;i<=m;i++){
            ans+=(wn[rn[i]]-wn[ln[i]-1])*(vn[rn[i]]-vn[ln[i]-1]);
        }
        res=std::min(res,llabs(ans-s));
        return ans<=s;
    };
    for (int i=1;i<=m;i++){
        std::cin>>ln[i]>>rn[i];
    }
    int l=0,r=1e9;
    while (l+1<r){
        int mid=l+r>>1;
        if (check(mid)){
            //需要得到最小值
            r=mid;
        }
        else{
            l=mid;
        }
    }
    std::cout<<res;
	return 0;
}