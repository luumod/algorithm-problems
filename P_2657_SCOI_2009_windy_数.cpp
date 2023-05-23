#include <bits/stdc++.h>

const int N=12;
int dp[N][10];
int l,r;
void init(){
    //预处理所有的windy数
    for (int i=0;i<=9;i++){
        dp[1][i]=1; //位数为1，最高位为i的windy数为其本身
    }
    for (int i=2;i<N;i++){
        for (int j=0;j<=9;j++){
            for (int z=0;z<=9;z++){
                if (abs(j-z)>=2){
                    dp[i][j]+=dp[i-1][z];
                }
            }
        }
    }
}
int solve(int num){
    //windy数： 相邻两个数字差值至少为2
    std::vector<int> nums;
    while (num){
        nums.push_back(num%10);
        num/=10;
    }
    int last=-2,ans=0; //last必须满足首先让最高位合法
    //如果 num= 9999
    //1. 首先统计位数等于size位的: 1000 - 9999
    for (int i=nums.size();i>=1;i--){
        int now=nums[i-1];
        for (int j=(i==nums.size());j<now;j++){ //j的最高位一定从1开始，因此对i==size进行特判
            if (abs(j-last)>=2){ //当前数字和前一位数字一定是满足的：差值至少为2
                ans+=dp[i][j];
            }
        }
        if (abs(now-last)<2){ 
            break; //不符合
        }
        last=now;
        if (i==1){
            ans++;
        }
    }
    //2. 然后统计位数小于size位的: 100-999 10-99 1-9
    for (int i=1;i<nums.size();i++){
        for (int j=1;j<=9;j++){ //从1开始，最高位不能是0
            ans+=dp[i][j];
        }
    }
    return ans;
}
int main(){
    init();
    std::cin>>l>>r;
    std::cout<<solve(r)-solve(l-1);
	return 0;
}