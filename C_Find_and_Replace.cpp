#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    std::array<int,26> ump;
    for (int i=0;i<26;i++){
        ump[i] = -1;
    }
    int cur = 0;
    bool fg = true;
    for (int i=0;i<s.size();i++){
        int ch = s[i]-'a';
        cur^=1;
        if (ump[ch]==-1){
            //第一次出现
            ump[ch] = cur;
        }
        else if (ump[ch]!=cur){
            //不是第一次出现，并且以前的记录值不等于当前值
            fg=false;
            break;
        }
    }
    if (fg){
        std::cout<<"YES\n";
    }
    else{
        std::cout<<"NO\n";
    }
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
	return 0;
}