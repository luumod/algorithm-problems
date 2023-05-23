#include <bits/stdc++.h>
typedef long long ll;
int main(){
    ll num,k;
    std::cin>>num>>k;
    if (k>(num+1)/2){
        //都是偶数的情况，单独处理出偶数
        k-=(num+1)/2;
        std::cout<<2*k;
    }
    else{
        //如果k小于它的一半，则直接输出即可，他们都是奇数
        std::cout<<2*k-1;
    }
    

    return 0;
}