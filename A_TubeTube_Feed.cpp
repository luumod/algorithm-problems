#include <bits/stdc++.h>

const int N = 1000;
void solve(){
    int n,t;
    std::cin>>n>>t;
    int v[N],f[N];
    for (int i=1;i<=n;i++){
        std::cin>>v[i];
    }
    for (int i=1;i<=n;i++){
        std::cin>>f[i];
    }
    int mx = 0,ans=-1;
    for (int i=t,j=1;i>=1 && j<=n;i--,j++){
        if (i>=v[j]){
            if (mx<f[j]){
                mx=f[j];
                ans=j;
            }
        }
    }
    std::cout<<ans<<'\n';
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
	return 0;
}