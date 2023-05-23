#include <bits/stdc++.h>
using ll=long long;

const int N=14;
ll dp[N][10][10]; //位数为i,最高位数字为j,k数字出现的次数 
int l,r;
void init(){
    for (int i=0;i<=9;i++){
        dp[1][i][i]=1; //个位数，i出现的次数为1次
    }
    for (int i=2;i<N;i++){
        for (int j=0;j<=9;j++){ //当前最高位数字
            for (int k=0;k<=9;k++){ //前一位最高位数字
                for (int z=0;z<=9;z++){ //某一个数字
                    //当前位为i,最高位数字j,z出现的次数 = 前一位i-1,最高位数字为k，z出现的次数进行《累加》
                    dp[i][j][z]+=dp[i-1][k][z];
                }
            }
            dp[i][j][j]+=pow(10,i-1);
        }
    }
}
ll solve(int x,int num){
    //num表示当前数字
    std::vector<int> vec;
    while (x){
        vec.push_back(x%10);
        x/=10;
    }
    int ans=0;
    int last=0;
    // for (int i=vec.size();i>=1;i--){
    //     int now=vec[i-1]; //当前位数字
    //     for (int j=last;j<now;j++){
    //         ans+=dp[i][j][num]; 
    //     }
    // }
    for (int i=1;i<vec.size();i++){
        for (int j=0;j<=9;j++){
            ans+=dp[i][j][num];
        }
    }
    for (int i=1;i<vec.size();i++){
        ans+=dp[vec.size()][]
    }
    return ans;
}
int main(){
    init();
    std::cin>>l>>r;
    for (int i=0;i<=9;i++){
        std::cout<<solve(r,i)-solve(l-1,i)<<' ';
    }
	return 0;
}