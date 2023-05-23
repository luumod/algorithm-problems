#include <bits/stdc++.h>

const int N=1010;
int w,b; //白鼠和黑鼠的数量
double dp[N][N]; //dp[i][j]表示袋子中有i只白鼠，j只黑鼠 时的A获胜的概率
int main(){
    std::cin>>w>>b;
    /*
    1. dp[i][0]=1 袋子中只有白鼠，A必胜
    2. dp[0][j]=0 袋子中没有白鼠，A必输
    3. dp[i][j-3] A先手摸黑鼠，B摸黑鼠，跑出一只黑鼠
    4. dp[i-1][j-2] A先手摸黑鼠，B摸黑鼠，跑出一只白鼠
    */
    for (int i=1;i<=w;i++){
        dp[i][0]=1;
    }
    for (int j=1;j<=b;j++){
        dp[0][j]=0;
    }
    for (int i=1;i<=w;i++){
        for (int j=1;j<=b;j++){
            dp[i][j]+=(double)i/(i+j);
            if (i>=1 && j>=2){
                dp[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*dp[i-1][j-2];
            }
            if (i>=0 && j>=3){
                dp[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*dp[i][j-3];
            }
        }
    }
    printf("%.9lf\n",dp[w][b]);
	return 0;
}