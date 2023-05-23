#include <bits/stdc++.h>

const int N=110,M=11;
std::vector<int> s; //存储状态
int num[1<<M]; //状态所对应的1的个数
int map[N]; //用十进制表示每一行的地图值
int dp[2][1<<M][1<<M]; //dp[i][a][b]: 当前行为i，当前状态为a，上一行状态为b 的炮兵数量
int n,m;
int main(){
    std::cin>>n>>m;
    //1. 地图预处理
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char ch;
            std::cin>>ch;
            if (ch=='P'){
                map[i]+=(1<<(m-j));//每一行转换为十进制数
            }
        }
    }
    //2. 存储列间合法状态
    for (int i=0;i<(1<<m);i++){
        if (!(i&i>>1) && !(i&i>>2)){//相邻一列和间隔的列都不能为1: error: 11 101
            s.push_back(i); //存储合法状态
            for (int j=0;j<m;j++){ //列：统计每一行的1的数量，对列枚举
                num[i]+=i>>j&1; //存储这一状态的炮兵(1)的数量
            }
        }
    }
    //3. 行间状态计算
    for (int i=1;i<=n+2;i++){ //多算2行
        for (int a=0;a<s.size();a++){
            for (int b=0;b<s.size();b++){
                for (int c=0;c<s.size();c++){
                    if (!(s[a]&s[b]) && !(s[a]&s[c]) && !(s[b]&s[c]) && (s[a]&map[i])==s[a] && (s[b]&map[i-1])==s[b]){
                        //当前行i状态为a，上一行为b的数量为i-1行，状态为b，上一行为c的数量+当前行i的数量
                        dp[i&1][a][b]=std::max(dp[i&1][a][b],dp[(i-1)&1][b][c]+num[s[a]]);
                    }
                }
            }
        }
    }
    std::cout<<dp[(n+2)&1][0][0];
	return 0;
}