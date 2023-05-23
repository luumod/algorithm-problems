#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    
    int j=0;
    for (int i=0;i<4;i++){
        char lo="meow"[i];
        char hi="MEOW"[i];
        if (j==n || (s[j]!=lo && s[j]!=hi)){
            std::cout<<"NO\n";
            return;
        }
        while (j<n && (s[j]==lo || s[j]==hi)){
            j++;
        }
    }
    if (j==n){ //正好遍历完整个字符串，如果末尾多了一个:M， 则 j<n
        std::cout<<"YES\n";
    }
    else{
        std::cout<<"NO\n";
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