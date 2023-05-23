#include <bits/stdc++.h>

void solve(){
    int n,d;
    std::cin>>n>>d;
    std::string s;
    std::cin>>s;
    for (int i=0;i<s.size();i++){
        if (s[i]>=d+'0'){
            std::cout<<s[i];
        }
        else{
            std::cout<<d;
            for (int j=i;j<s.size();j++){
                std::cout<<s[j];
            }
            std::cout<<'\n';
            return;
        }
    }
    std::cout<<d<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}