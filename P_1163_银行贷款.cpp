#include <bits/stdc++.h>

int main(){
    int n,k,m; // 原值 分期付款金额 还清的总共月数
    std::cin>>n>>k>>m; 
    /*
    过去每个月之后还剩下多少未还？ 设利率为p
    n=n*(1+p/100)-k;
    */
    auto check=[&](double mid){
        double nn=n;
        for (int i=1;i<=m;i++){
            nn=nn*(1+mid)-k;
        }
        return nn<=0; //如果最后还剩<=0,则说明此在利率下还清了，则返回true
    };
    //二分利率
    double l=0,r=10;
    while (r-l>1e-5){
        double mid=(l+r)/2;
        if (check(mid)){ 
            l=mid; //还清了，寻找最大的符合的利率
        }
        else{   
            r=mid;
        }
    }
    printf("%.1lf\n",r*100); // *100
    return 0;
}