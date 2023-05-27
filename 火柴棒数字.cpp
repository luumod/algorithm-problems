#include <bits/stdc++.h>
#define int long long
const int N=1000;
int w[N]{6,2,5,5,4,5,6,3,7,6};
/*
完全背包
每个火柴的重量就是摆放数量，价值就是自身的值
每个物品最多有十件
*/
int dp[N]; //dp[i]背包容量为i时的最大价值
std::vector<int> vec;
signed main(){
    for (int i=0;i<10;i++){ 
        for (int j=300;j>=w[i];j--){
            for (int k=0;k<=10 && k*w[i]<=j;k++){
                if (dp[j]<dp[j-k*w[i]]+k*i){
                    dp[j]=dp[j-k*w[i]]+k*i; 
                    vec.push_back(k*i);
                }
            }
        }
    }
    for (int i=1;i<=300;i++){
        std::cout<<dp[i]<<" \n"[i==300];
    }
    for (auto& x:vec){
        std::cout<<x<<' ';
    }
	return 0;
}   