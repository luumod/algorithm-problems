#include <bits/stdc++.h>

const int N=350000;
int main(){
    int n;
    std::cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++){
        int num;
        std::cin>>num;
        ans^=num;
    }
    std::cout<<ans;
	return 0;
}