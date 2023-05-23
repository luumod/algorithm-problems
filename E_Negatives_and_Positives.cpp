#include <bits/stdc++.h>

typedef long long ll;
void solve(){
    int n;
    std::cin>>n;
    ll neg=0,ans=0,sum=0;
    ll mi=1e9;
    for (int i=1;i<=n;i++){
        ll num;
        std::cin>>num;
        if (num<0){
            neg++; //neg^=1  统计负数的个数
            num=-num;
        }
        sum+=num;
        mi=std::min(mi,num);
    }
    if (neg&1){
        //如果负数的个数为奇数，则两两操作，最后只剩一个负数，最大值就是减去最小的负数
        sum-=2*mi;
    }
    //如果负数个数为偶数，则一定最后没有负数
    std::cout<<sum<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}