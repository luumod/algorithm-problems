#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;//n进制

    std::string num;
    std::cin>>num;
    
    int dst;
    std::cin>>dst;

    //n进制转换为d进制
    //首先把src进制的num转换为10进制
    std::unordered_map<char,int> ump1;
    std::unordered_map<int,char> ump2;
    for (char i=0;i<=9;i++){
        ump1[i+'0']=i;
    }
    for (char c='A';c<='F';c++){
        ump1[c]=c-'A'+10;
    }
    for (int i=0;i<=9;i++){
        ump2[i]=i+'0';
    }
    for (int i=10;i<=15;i++){
        ump2[i]=i-10+'A'; 
    }

    int snum=0;
    std::reverse(num.begin(),num.end());
    for (int i=0;i<num.size();i++){
        snum+=ump1[num[i]]*pow(n,i);
    }
    //snum为十进制数，再把它转换为dst进制
    std::string s;
    if (dst==10){
        std::cout<<snum;
    }
    else{
         //十进制转换二进制
        while (snum){
            s.push_back(ump2[snum%dst]); 
            snum/=dst;
        }
    }
    std::reverse(s.begin(),s.end());
    std::cout<<s;

	return 0;
}