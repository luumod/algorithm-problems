#include <bits/stdc++.h>

typedef long long ll;
ll a,b,mod;
ll quick_mi(ll a,ll b,ll mod){
    ll ans=1;
    while (b){
        if (b&1){ // 1101： 2^8 * 2^4 * 2^0
            ans=ans*a%mod;
        }
        a=a*a%mod; //底数按位倍增： 1 2 4 8 16 ...
        b>>=1; //指数拆分
    }
    return ans;
}
int main(){
    std::cin>>a>>b>>mod;
    printf("%lld^%lld mod %lld=%lld",a,b,mod,quick_mi(a,b,mod));
	return 0;
}