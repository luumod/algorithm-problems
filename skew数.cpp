#include <bits/stdc++.h>

const int N=1e6+10;
int vis[N],p[N],a[N],d[N]; //约数个数
int g[N],f[N]; //约数和
int mu[N]; //莫比乌斯函数
void find(int n){
    int c=0;
    for (int i=2;i<=n;i++){
        if (!vis[i]){
            p[++c] = i;
            //质数的质因子个数为1，约数个数为2
            a[i]=1,d[i]=2;
            //约数和
            g[i]=f[i]=i+1;
            //莫比乌斯函数
            mu[i]=-1; //质因子个数只有一个
        }
        for (int j=1;i*p[j]<=n;j++){
            int m=i*p[j];
            vis[m]=true;
            if (i%p[j]==0){
                //约数个数
                a[m]=a[i]+1;
                d[m]=d[i]/a[m]*(a[m]+1);
                //约数和
                g[m]=g[i]*p[j]+1;
                f[m]=f[i]/g[i]*g[m];
                //莫比乌斯函数
                mu[m]=0; //含有相同的质因子
                break;      
            }
            else{
                //m=2*5=10 是一个合数：质因子只有一个，约数个数为d[i]*2   
                a[m]=1,d[m]=d[i]*2;
                //约数和
                g[m]=p[j]+1;
                f[m]=f[i]*g[m];
                //莫比乌斯函数
                mu[m]=-mu[i];
            }
        }
    }
}
int main(){
    int n;
    find(10);
    for (int i=1;i<=10;i++){
        std::cout<<d[i]<<' ';
    }
	return 0;
}