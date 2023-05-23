#include <bits/stdc++.h>


std::string s;
void solve1(){
    //转小写
    for (auto &x:s){
        x=tolower(x);
    }
    std::cout<<s;
}
void solve2(){
    s[0]=toupper(s[0]);
    for (int i=1;i<s.size();i++){
        s[i]=tolower(s[i]);
    }
    std::cout<<s;
}
int main(){
    std::cin>>s;
    bool up=true;
    for (int i=1;i<s.size();i++){
        if (islower(s[i])){
            up=false;
        }
    }
    if (islower(s[0]) && up){
        //1小后大
        solve2();
    }
    else if (isupper(s[0]) && up){
        //全大写
        solve1();
    }
    else{
        std::cout<<s;
    }
	return 0;
}