#include <bits/stdc++.h>

void solve(){
    std::string s,d="codeforces";
    std::cin>>s;

    int cnt=0;
    for (int i=0;i<s.size();i++){
        if (s[i]!=d[i]){
            cnt++;
        }
    }
    std::cout<<cnt<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}