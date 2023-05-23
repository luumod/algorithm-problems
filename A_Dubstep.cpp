#include <bits/stdc++.h>

int main(){
    std::string s;
    std::cin>>s;
    std::string dst;
    for (int i=0;i<s.size();i++){
        if (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){
            i+=2;
            if (!dst.empty() && dst.back()!=' '){
                dst.push_back(' ');
            }
        }
        else{
            dst.push_back(s[i]);
        }   
    }
    std::cout<<dst;
	return 0;
}