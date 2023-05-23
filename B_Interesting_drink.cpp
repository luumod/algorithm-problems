#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
    }
    std::sort(vec.begin()+1,vec.begin()+1+n);
    int q;
    std::cin>>q;
    while (q--){
        int tar;
        std::cin>>tar;
        int ans=0;
        /*
        1: 
        */
        ans=std::upper_bound(vec.begin()+1,vec.begin()+1+n,tar)-vec.begin()-1;
        std::cout<<ans<<'\n';
    }
    
	return 0;
}