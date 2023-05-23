#include <bits/stdc++.h>

const int N=10;
long long dp[N][N*N][1<<11];
std::vector<int> s; //合法状态数量 state
int num[1<<11];  //num[i]: 每个合法状态的国王数量，即1的个数
int main(){
    int n,k;
    std::cin>>n>>k;
    //1. 状态记录，处理列之间的兼容性
    for (int i=0;i<(1<<n);i++){
        if (!(i&(i>>1))){//不是相邻的1
            s.push_back(i); //状态合法，记录
            for (int j=0;j<n;j++){ //枚举此状态的所有可能的国王数量
                if (i>>j&1){
                    num[i]++;    
                }
            }
        }
    }
    //2. 枚举状态，处理行之间的兼容性
    dp[0][0][0]=1;
    for (int i=1;i<=n+1;i++){ //枚举每一行
        for (int j=0;j<=k;j++){ //枚举国王数
            for (int a=0;a<s.size();a++){ //枚举第i行的合法状态
                for (int b=0;b<s.size();b++){//枚举第i-1行的合法状态
                    //每一个合法状态的相邻两行都是合法的。
                    if (j-num[s[a]]>=0 && !(s[a]&s[b]) && !(s[a]&(s[b]<<1)) && !(s[a]&(s[b]>>1))){
                        dp[i][j][a]+=dp[i-1][j-num[s[a]]][b];
                    }
                }
            }
        }
    }
    // long long ans=0;
    // for (int i=0;i<s.size();i++){
    //     ans+=dp[n][k][i];
    // }
    std::cout<<dp[n+1][k][0];
	return 0;
}