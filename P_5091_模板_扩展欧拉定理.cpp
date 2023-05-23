#include <bits/stdc++.h>

using ll=long long;
ll a,p;
std::string b;
ll oula(ll n){
    //求余数的欧拉函数
    ll ans=n;
    for (int i=2;1ll*i*i<=n;i++){
        if (n%i==0){ //分解质因数
            ans=ans/i*(i-1);
            while (n%i==0){
                n/=i;
            }
        }
    }
    if (n>1){
        ans=ans/n*(n-1);
    }
    return ans;
}
int delow(ll phi){
    int ansB=0;
    bool fg=false;
    for (int i=0;i<b.size();i++){
        ansB=ansB*10+(b[i]-'0'); //秦九韶算法
        if (ansB>=phi){
            fg=true;
            ansB%=phi; //降降幂
        }
    }
    if (fg){
        ansB+=phi;
    }
    return ansB;
}
ll quick_mi(ll a,ll b,ll p){
    ll ans=1;
    while (b){
        if (b&1){
            ans=ans*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
int main(){
    std::cin>>a>>p>>b;
    //1. 扩展欧拉定理降幂
    ll phi=oula(p); //求p余数的欧拉函数
    int db=delow(phi);
    //2. 快速幂
    std::cout<<quick_mi(a,db,p);
	return 0;
}