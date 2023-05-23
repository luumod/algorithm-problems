#include <bits/stdc++.h>

const int N=1e8+10;
int n,q;
int primes[N];
bool vis[N];
void getPrimes(){
    int cnt=0;
    for (int i=2;i<=n;i++){
        if (!vis[i]){
            primes[++cnt]=i;
        }
        for (int j=1;1ll*i*primes[j]<=n;j++){ //越界中断
            vis[i*primes[j]]=true;
            if (i%primes[j]==0){ //整除中断
                break;
            }
        }
    }
}
void solve(){
    std::cin>>n>>q;
    getPrimes();
    for (int i=1;i<=q;i++){
        int k;
        std::cin>>k;
        std::cout<<primes[k]<<'\n';
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    solve();
	return 0;
}