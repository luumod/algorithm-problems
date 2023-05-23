#include <bits/stdc++.h>

int main(){
    int n,t;
    std::cin>>n>>t;
    if (t==10){
        if (n==1){
            std::cout<<-1;
            return 0;
        }
        std::string s(n,0+'0');
        s.front()='1';
        std::cout<<s;
    }
    else{
        std::string s(n,t+'0');
        std::cout<<s;
    }
   
	return 0;   
}