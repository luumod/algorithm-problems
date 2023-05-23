#include <bits/stdc++.h>

int main(){
    const int N=32;
    int n;
    std::cin>>n;
    std::string s =std::bitset<N>(n).to_string();
    //std::bitset<N> ans{0};
    for (int i=0;i<16;i++){
        std::swap(s[i],s[N/2+i]);
    }
    std::reverse(s.begin(),s.end());
    long long ans=0;
    for (int i=0;i<N;i++){
        ans+=(s[i]-'0')*pow(2,i); //1<<i
    }
    std::cout<<ans;
    //std::cout<<ans.to_ullong();
	return 0;
}