#include <bits/stdc++.h>

const int N=1e6+10;
std::vector<std::string> vec(N);
int main(){
    int n;
    std::cin>>n;
    std::map<std::string,int> ump;
    int k=0;
    while (n--){
        std::string s;  
        std::cin>>s;
        if (ump.count(s)){
            //栈顶  
            ump[s]=k++;
        }
        else{
            ump[s]=k++;
        }
    }
    for (auto& x:ump){
        vec[x.second]=x.first;
    }
    for (int i=vec.size()-1;i>=0;i--){
        if (vec[i]!=""){
            std::cout<<vec[i]<<'\n';
        }
    }
	return 0;
}