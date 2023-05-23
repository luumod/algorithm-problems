#include <bits/stdc++.h>

int main(){
    int cnt;
    std::cin>>cnt;
    while (cnt--){
        int a,b,c;
        std::cin>>a>>b>>c;
        if (a+b ==c){
            std::cout<<'+'<<'\n';
        }
        else if (a-b==c){
            std::cout<<'-'<<'\n';
        }
    }   
	return 0;
}