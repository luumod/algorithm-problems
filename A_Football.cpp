#include <bits/stdc++.h>

int main(){ 
    int n;
    std::cin>>n;
    std::unordered_map<std::string,int> t;
    for (int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        t[s]++;
    }
    std::string pname;
    int ans=0;
    for (auto &x:t){
        if (x.second>ans){
            ans=x.second;
            pname=x.first;
        }
    }
    std::cout<<pname;
	return 0;
}