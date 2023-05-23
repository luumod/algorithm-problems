#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>

int main(){
    int n,k;
    while (std::cin>>n>>k){
        if (n==0 && k==0){
            break;
        }
        std::vector<double> A(n+1),B(n+1),C(n+1);
        for (int i=1;i<=n;i++){
            std::cin>>A[i];
        }
        for (int i=1;i<=n;i++){
            std::cin>>B[i];
        }
        //分数规划：转换为以 ai-x*bi 为新的权值而产生的最大值
        auto check=[&](double x){
            for (int i=1;i<=n;i++){
                C[i]=A[i]-x*B[i];  //转换为新的权值
            }
            std::sort(C.begin()+1,C.begin()+1+n);
            //去掉k个成绩，则选择剩余最大的n-k个成绩
            double sum=0;
            for (int i=k+1;i<=n;i++){
                sum+=C[i];
            }
            return sum>=0; //求最大值
        };
        double l=0,r=1;
        while (r-l>1e-5){
            double mid=(l+r)/2;
            if (check(mid)){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        printf("%.0lf\n",l*100);
    }
	return 0;
}