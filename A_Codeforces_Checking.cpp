#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::string s="codeforces";
    for (int i=1;i<=n;i++){
        char ch;
        std::cin>>ch;
        if (s.find(ch)!=std::string::npos){
            std::cout<<"YES\n";
        }
        else{
            std::cout<<"NO\n";
        }
    }
	return 0;
}