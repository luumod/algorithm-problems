#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int ll p=1000000007;

int k;
ll r,n[25],inv[25];

ll pow(ll a,ll b,ll p){
    ll ans=1;
    while(b){
        if (b%2) ans=(ans*a)%p;
        b/=2;
        a=(a*a)%p;
    }
    return ans;
}

void get_inv(ll n,ll p){
    inv[1]=1;
    for (ll i=2;i<=n;i++){
        inv[i]=inv[p%i]*(p-p/i)%p;
    }
}

int C(ll y,ll x){
    if (y<0||x<0||y<x) return 0;
    y%=p;
    if (y==0 || x==0) return 1;
    ll ans=1;
    for (int i=0;i<x;i++){
        ans=1ll*ans*(y-i)%p;
    }
    for (int i=1;i<=x;i++){
        ans=1ll*ans*inv[i]%p;
    }
    return ans;
}

int main(){
    get_inv(20,p);
    scanf("%d%lld",&k,&r);
    ll ans=C(k+r-1,k-1);
    for (int i=1;i<=k;i++){
        scanf("%lld",&n[i]);
    }
    for (int x=1;x<1<<k;x++){
        ll t=k+r,num=0;
        for (int i=0;i<k;i++){
            if (x>>i & 1) num++,t-=n[i+1];
        }
        t-=num+1;
        if (num%2==1) ans=(ans-C(t,k-1))%p;
        else ans=(ans+C(t,k-1))%p;
    }
    printf("%lld",(ans+p)%p);
    return 0;
}