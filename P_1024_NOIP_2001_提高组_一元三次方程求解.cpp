#include <bits/stdc++.h>

double a,b,c,d;
inline double get(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
double find(double l,double r){
    while (r-l>1e-5){
        double mid=(l+r)/2;
        if (get(mid)*get(r)<0){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    return l;//寻找最大的
}
int main(){
    std::cin>>a>>b>>c>>d;
    for (int i=-100;i<=100;i++){
        double y1=get(i),y2=get(i+1);
        if (!y1){
            printf("%.2lf ",1.0*i);
        }
        if (y1*y2<0){
            printf("%.2lf ",find(i,i+1));
        }
    }
	return 0;
}