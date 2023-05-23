#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    if (n>0){
        std::cout<<n;
    }
    else{
        n=-n;
        auto s = std::to_string(n);
        auto temp=s;
        //before last
        auto ss= s.erase(--(--s.end()));
        //last
        temp.pop_back();
        //to postive --> find min num
        int res = std::min(std::stoi(s),std::stoi(temp));
        std::cout<<-res;
    }
	return 0;
}