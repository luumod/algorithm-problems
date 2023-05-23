#include <bits/stdc++.h>
using ll=long long;

const int mod=1e9+7;
int n; //第n项
struct Node{
    ll matrix[3][3];
    Node(){
        memset(matrix,0,sizeof(matrix));
    }
}ans,A;
Node operator*(const Node& l,const Node& r){
    Node t;
    for (int i=1;i<=2;i++){ //新矩阵行数
        for (int j=1;j<=2;j++){ //新矩阵列数
            for (int k=1;k<=2;k++){ //前列和右行
                t.matrix[i][j]=(t.matrix[i][j]+l.matrix[i][k]*r.matrix[k][j])%mod;
            }
        }
    }
    return t;
}
void Fibo_Quick(int n){
    if (n<=2){
        return;
    }
    ans.matrix[1][1]=1,ans.matrix[1][2]=1; //前两项
    //递推矩阵
    A.matrix[1][1]=1,A.matrix[1][2]=1,A.matrix[2][1]=1,A.matrix[2][2]=0;
    n-=2; //求递推矩阵的n-2次方
    while (n){
        if (n&1){
            ans=ans*A;
        }
        A=A*A;
        n>>=1;
    }
}
int main(){
    std::cin>>n;
    Fibo_Quick(n);
    if (n==1){
        std::cout<<1;
    }
    else if (n==2){
        std::cout<<1;
    }
    else{
        std::cout<<ans.matrix[1][1];
    }
	return 0;
}