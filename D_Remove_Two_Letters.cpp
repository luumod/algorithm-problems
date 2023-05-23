#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    int ans=n-1;
    for (int i=0;i+2<s.size();i++){
        ans-=(s[i]==s[i+2]);
    }
    std::cout<<ans<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}