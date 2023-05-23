#include <bits/stdc++.h>

int main(){
    int s,n;
    std::cin>>s>>n;
    std::vector<std::pair<int,int>> pos;
    for (int i=1;i<=n;i++){
        int a,b;
        std::cin>>a>>b;
        pos.push_back({a,b});
    }
    std::sort(pos.begin(),pos.end());
    for (int i=0;i<n;i++){
        if (s<=pos[i].first){    
            std::cout<<"NO\n";
            return 0;
        }
        else{
            s+=pos[i].second;
        }
    }
    std::cout<<"YES\n";
	return 0;
}