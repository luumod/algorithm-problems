#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e5+10;
int n,m;
int ans[3][N]{};
void solve(){
    memset(ans,0,sizeof(ans));
    std::cin>>n;
    int np=n*2,npn=2;
    for (int j=1;j<=n;j++){
        if (j&1){
            ans[1][j]=np;
            if (j>1){
                ans[2][j-1]=np-1;
            }
            np-=2;
        }
        else{
            ans[1][j]=npn;
            if (j>1){
                ans[2][j-1]=npn-1;
            }
            npn+=2;
        }
    }
    ans[2][n]=n*2-1;
    for (int i=1;i<=2;i++){
        for (int j=1;j<=n;j++){
            std::cout<<ans[i][j]<<" \n"[j==n];
        }
    }
}
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}