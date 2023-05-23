#include <bits/stdc++.h>

const int N=510;
int p;
std::vector<int> A(N),ans(N);
std::vector<int> big_mul(const std::vector<int>& a,const std::vector<int>& b){
    std::vector<int> t(N<<1);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            t[i+j]+=a[i]*b[j];
            t[i+j+1]+=t[i+j]/10;
            t[i+j]%=10;
        }
    }
    //低位在前，高位在后
    return t;
}
void quick_big_mi(int p){
    ans[0]=1,A[0]=2;
    while (p){
        if (p&1){ //底数倍增
            ans=big_mul(ans,A);
        }
        A=big_mul(A,A);
        p>>=1; //指数拆分
    }
    ans[0]--; //最后一位-1
}
int main(){
    std::cin>>p;
    std::cout<<ceil(p*log10(2))<<' ';
    quick_big_mi(p);
    for (int i=500;i>=1;i--){
        if (i%50==0){
            std::cout<<'\n';
        }
        std::cout<<ans[i-1];
    }
    return 0;
}