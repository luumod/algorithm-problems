#include <bits/stdc++.h>
#define int long long
const int A[]{0,1,2,3,5,6,7,8,9};
void solve(){
    int num;
    std::cin>>num;
    std::vector<int> arr;
    while (num){
        arr.push_back(A[num%9]);
        num/=9;
    }
    std::reverse(arr.begin(),arr.end());
    for (auto& x:arr){
        std::cout<<x;
    }
    putchar('\n');
}
signed main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}