#include <bits/stdc++.h>

void change(int n,int r){
    if (n==0){
        return;
    }
    int yu=n%r; //余数
    
    //如果余数小于0，则转换为正数: 余数-除数 被除数+除数
    if (yu<0){
        yu-=r;
        n+=r;
    }
    if (yu>=10){
        yu=yu-10+'A';
    }
    else{
        yu=yu+'0';
    }
    change(n/r,r);

    std::cout<<char(yu);
}
int main(){
    int n;
    std::cin>>n;
    int base;
    std::cin>>base;

    std::cout<<n<<"=";
    change(n,base);
    std::cout<<"(base"<<base<<")";

    std::cout<<'\n';
    int p=-15%2; // ... -1
    // -15-2 = -17
    int d=-13%2; // -1 - -2 = 1
    std::cout<<p<<' '<<d;
	return 0;
}