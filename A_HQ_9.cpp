#include <bits/stdc++.h>

int main(){
    std::string s;
    std::cin>>s;
    for (auto &x:s){
        if (x=='H' || x=='Q' || x=='9'){
            std::cout<<"YES\n";
            return 0;
        }
    }
    std::cout<<"NO\n";
	return 0;
}