#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<std::pair<int,int>> vec(n+1);
    int mx=0;
    for (int i=1;i<=n;i++){
        int p,v;
        std::cin>>p>>v;
        vec[i]={p,v};
    }
    std::sort(vec.begin()+1,vec.begin()+1+n);
    int mi=vec[1].second;
    for (int i=2;i<=n;i++){
        if (mi>vec[i].second){
            std::cout<<"Happy Alex\n";
            return 0;
        }
        else if (mi<vec[i].second){
            mi=vec[i].second;//mininum
        }
    }
    std::cout<<"Poor Alex\n";
	return 0;   
}