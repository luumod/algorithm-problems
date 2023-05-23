#include <bits/stdc++.h>
#define int long long
const int N=15;
int dp[N][1<<N]; //dp[i][j]表示当前列为i，状态为j时的方案数
signed main(){
    int n,m;
    while (std::cin>>n>>m){
        if (n==0 && m==0){
            break;
        }
        memset(dp,0,sizeof(dp));
        std::vector<bool> s(1<<N,true); //存储状态
        for (int i=0;i<(1<<n);i++){ //遍历所有可能的《每一列》 其中每一列有n个数字
            int cnt=0;
            for (int j=0;j<n;j++){
                if (i>>j&1){
                    if (cnt&1){//如果出现的0的个数为奇数则表示一定是非法的。
                        s[i]=false;
                        break;
                    }
                }
                else{
                    cnt++;
                }
            }
            if (cnt&1){//检查最高位
                s[i]=false;
            }
        }
        dp[0][0]=1;//当前为第0列，状态为0，是一种初始状态，说明全是竖着的。
        for (int i=1;i<=m;i++){//遍历所有列
            for (int a=0;a<1<<n;a++){//当前列状态
                for (int b=0;b<1<<n;b++){//前一列状态
                    if (!(a&b) && s[a|b]){
                        // !(a&b): 表示不存在连续的1，如果i-1：1001 ，i：0001，则最低位的1是非法的，因为如果前一列为1，当前一定为0才是合法的
                        //  s[a|b]:表示不存在奇数个0，1001 0100 是非法的，s[1001|0100]=s[15]=false
                        dp[i][a]+=dp[i-1][b];
                    }
                }
            }
        }
        std::cout<<dp[m][0]<<'\n';
    }
	return 0;
}