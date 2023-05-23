#include <bits/stdc++.h>

const int N=15,mod=1e8;
int map[N]; //存储地图，将每一行转换为十进制数
long long dp[N][1<<13]; //dp[i][j]: 第i行状态为j时的方案数
std::vector<int> s;//存储状态
int n,m;
int main(){
    std::cin>>n>>m;
    //1. 地图转换为十进制表示
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int x;
            std::cin>>x;
            map[i]=(map[i]<<1)+x;
        }
    }
    //2. 存储合法状态，未给出准确的物品数量限制，因此不用存储玉米的每一个状态的数量
    for (int i=0;i<(1<<m);i++){
        if (!(i&i>>1)){
            s.push_back(i);//保存合法状态
        }
    } 
    dp[0][0]=1; //边界设置
    for (int i=1;i<=n+1;i++){ //枚举每一行
        for (int a=0;a<s.size();a++){ //枚举当前行状态
            for (int b=0;b<s.size();b++){ //枚举上一行状态
                if (!(s[a]&s[b]) && (map[i]&s[a])==s[a]){ //如果相邻两行是合法的
                    //当前行状态由上一行转移得到
                    dp[i][a]=(dp[i][a]+dp[i-1][b])%mod;
                }
            }
        }
    }
    // long long ans=0;
    // for (int i=0;i<s.size();i++){
    //     ans+=dp[n][i];
    // }
    std::cout<<dp[n+1][0];
	return 0;
}