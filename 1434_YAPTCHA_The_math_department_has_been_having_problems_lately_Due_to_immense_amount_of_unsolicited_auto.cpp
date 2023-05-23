#include <bits/stdc++.h>

using ll=long long;
const int N=1e6+10;
int p[N*3];
int vis[N*3];
ll ans[N*3];
void primes(){
    for (int i=2;i<N*3;i++){
        if (!vis[i]){
            if ((i-7)%3==0){ // p=3k+7  --> k
                p[(i-7)/3]=1;
            }
            if ((ll)i*i<=N){
                for (int j=i*i;j<=N;j+=i){
                    vis[j]=true;
                }
            }
        }
    }
}
int main(){
    primes();
    for (int i=1;i<N;i++){
        ans[i]=ans[i-1]+p[i];
    }
    int n;
    std::cin>>n;
    while (n--){
        int x;
        std::cin>>x;
        std::cout<<ans[x]<<'\n';
    }
	return 0;
}