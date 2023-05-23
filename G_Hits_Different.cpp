#include <bits/stdc++.h>
#define int long long

const signed N=1500; //n(n+1)/2 >= 1000000
int dp[N][N];
int cx[N*N],cy[N*N];
void solve(){
    int cur=1;
    for (signed s=0;s<N;s++){
        for (signed j=0;j<=s;j++){
            int i=s-j;
            cx[cur]=i;
            cy[cur]=j;
            dp[i][j]=cur*cur;
            if (i){
                dp[i][j]+=dp[i-1][j];
            }
            if (j){
                dp[i][j]+=dp[i][j-1];
            }
            if (i&&j){
                dp[i][j]-=dp[i-1][j-1];
            }
            cur++;
        }
    }
}
signed main(){
    solve();
    int l;
    std::cin>>l;
    while (l--){
        int n;
        std::cin>>n;
        std::cout<<dp[cx[n]][cy[n]]<<'\n';
    }  
	return 0;
}