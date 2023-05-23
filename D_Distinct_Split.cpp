#include <bits/stdc++.h>

void solve(){
    int n;
    std::string s;
    std::cin>>n>>s;
    std::unordered_map<char,int> ori;
    for (int i=0;i<s.size();i++){
        ori[s[i]]++;
    }
    int mx=0;
    std::unordered_map<char,int> st1;
    for (int i=0;i<s.size();i++){
        st1[s[i]]++;
        ori[s[i]]--;
        if (ori[s[i]]==0){
            ori.erase(s[i]);
        }
        mx = std::max(mx,(int)st1.size()+(int)ori.size());
    }
    std::cout<<mx<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}