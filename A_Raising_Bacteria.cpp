#include <bits/stdc++.h>

#define int long long
std::string get(int num){   
    std::string s;
    while (num){
        int d=num%2;
        s+=d==1?'1':'0';
        num/=2;
    }
    return s;
}
signed main(){ 
    int n;
    std::cin>>n;
    std::string r=get(n);
    std::reverse(r.begin(),r.end());
    int cnt=0;
    for (auto& x:r){
        cnt+=x=='1'?1:0;
    }
    std::cout<<cnt;
	return 0;
}