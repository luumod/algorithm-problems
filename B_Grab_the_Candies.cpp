#include <bits/stdc++.h>

int main(){
    int cnt;
    std::cin>>cnt;
    while (cnt--){
        int n;
        std::cin>>n;
        int a,num1=0,num2=0;
        for (int i=1;i<=n;i++){
            std::cin>>a;
            if (a%2==0){
                num1+=a;
            }
            else{
                num2+=a;
            }
        }
        if (num1>num2){
            std::cout<<"YES\n";
        }
        else{
            std::cout<<"NO\n";
        }
    }
	return 0;
}