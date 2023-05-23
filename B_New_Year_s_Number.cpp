#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    int r=n%2020;   //需要的2021的个数
    int num=n/2020; //2020的个数
    //r=1 2 3 ...  <=num 说明可以使用若干个2021来使得增加1
    //r=0.99 0.80 ... 说明无法使用2021来合成
    if (r<=num){
        std::cout<<"YES\n";
    }
    else{
        std::cout<<"NO\n";
    }
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}