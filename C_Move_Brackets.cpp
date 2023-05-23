#include <bits/stdc++.h>

void solve(){
    int n;
    std::string s;
    std::cin>>n>>s;
    int ans=0;
    int cnt=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='('){
            cnt++;
        }
        else if (s[i]==')'){
            cnt--;
        }
        if (cnt<0){
            ans++;
            cnt=0;
        }
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