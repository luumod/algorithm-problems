#include <bits/stdc++.h>

void solve(){
    int num;
    std::cin>>num;
    long long ans=0;
    for (int i=2;i<=30;i++){
        int p=pow(2,i)-1;
        if (num%p==0){ 
            std::cout<<num/p<<' '; 
            break;
        }
    }
    putchar('\n');
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}