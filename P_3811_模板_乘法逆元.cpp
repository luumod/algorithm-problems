#include <bits/stdc++.h>

using ll=long long;
ll quick_mi(ll a,ll b,int p){
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
//扩展欧几里得算法
int expgcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int x0,y0,d;
    d=expgcd(b,a%b,x0,y0);
    x=y0,y=x0-a/b*y0;
    return a;
}
void solve(){
    int n,p; //求[1,n]范围内的所有数字的乘法逆元
    std::cin>>n>>p;
    for (int i=1;i<=n;i++){
         //printf("%lld\n",quick_mi(i,p-2,p));
        int x,y,d;
        d=expgcd(i,p,x,y);
        std::cout<<((x%p+p)%p)<<'\n';
    }
}   
int main(){
    solve();
	return 0;
}