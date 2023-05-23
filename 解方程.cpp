#include <bits/stdc++.h>
#define int long long
signed main(){
    int a,b,c;
    std::cin>>a>>b>>c;
    double x1=(-b+(sqrt(b*b-4*a*c)))/2*a,x2=(-b-(sqrt(b*b-4*a*c)))/2*a;
    if (x1<x2){
        std::swap(x1,x2);
    }
    printf("%.6lf\n%.6lf",x1,x2);
	return 0;
}