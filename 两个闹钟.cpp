#include <bits/stdc++.h>

//扩展欧几里得算法
int a,b,c;
int exgcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int x0,y0,d;
    d=exgcd(b,a%b,x0,y0);
    x=y0,y=x0-a/b*y0;
    return d;
}
int main(){
    int x,y;
    std::cin>>a>>b>>c; //ax+by=c
    int d=exgcd(a,b,x,y);
    if (c%d==0){
        std::cout<<c/d*x<<' '<<c/d*y<<'\n';
    }
    else{
        std::cout<<"none\n";
    }
    return 0;
}