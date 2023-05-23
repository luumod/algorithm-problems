#include <bits/stdc++.h>

int main(){
    int n,m;
    std::cin>>n>>m;
    if (n>m){
        std::swap(n,m);
    }
    if (n&1){
        std::cout<<"Akshat\n";
    }
    else{
        std::cout<<"Malvika\n";
    }
	return 0;
}