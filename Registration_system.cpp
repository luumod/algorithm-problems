#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::unordered_map<std::string,int> ump;
    for (int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        if (!ump.count(s)){
            ump[s]=0;
            std::cout<<"OK\n";
        }
        else{
            ump[s]++;
            std::cout<<s<<ump[s]<<'\n';
        }
    }
	return 0;
}