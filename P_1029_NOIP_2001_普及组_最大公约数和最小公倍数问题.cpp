#include <bits/stdc++.h>

using ll=long long;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int x,y;
    std::cin>>x>>y; //x为maxgcd y为maxlcm
    int sum=x*y;
    int ans=0;
    for (int i=1;i*i<=sum;i++){
        if (sum%i==0 && gcd(i,sum/i)==x){
            //1. i为其中一个数,必须要满足能被sum整除
            //2. sum/i和i的gcd为x
            //满足两条性质即可
            ans+=2;
        }
    } 
    if (x==y){
        //5 5  25 --> (5,5)
        ans--;
    }
    std::cout<<ans;
	return 0;
}