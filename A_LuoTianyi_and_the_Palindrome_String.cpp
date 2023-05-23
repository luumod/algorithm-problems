#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::cin>>s;
    bool fg=false;
    std::unordered_set<char> st;
    for (auto& x:s){
        st.insert(x);
    }
    if (st.size()==1){
        std::cout<<-1<<'\n';
    }
    else{
        std::cout<<s.size()-1<<'\n';
    }
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}