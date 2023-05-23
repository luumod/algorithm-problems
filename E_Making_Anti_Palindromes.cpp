#include <bits/stdc++.h>

void solve(){
    int n;
    std::string s;
    std::cin>>n>>s;
    if (n&1){
        std::cout<<-1<<'\n';
        return;
    }
    std::vector<int> fir(26,0);
    for (int i=0;i<n;i++){
        fir[s[i]-'a']++;
    }
    for (auto& x:fir){
        if (x>n/2){
            std::cout<<-1<<'\n';
            return;
        }
    }
    std::vector<int> arr(26,0);
    for (int i=0;i<n/2;i++){
        if (s[i]==s[n-i-1]){
            ++arr[s[i]-'a'];
        }
    }
    int ans=0;
    std::multiset<int> mst;
    for (auto &x:arr){
        if (x){
            mst.insert(x);
        }
    }
    while (mst.size()>1){
        auto l=mst.begin();
        auto r=mst.end();
        r--;
        int x=(*l)-1;
        int y=(*r)-1;
        mst.erase(l);
        mst.erase(r);
        if (x){
            mst.insert(x);
        }
        if (y){
            mst.insert(y);
        }
        ++ans;
    }
    if (mst.size()>0){
        ans+=*mst.begin();
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