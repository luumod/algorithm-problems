#include <bits/stdc++.h>

using ll=long long;
//n*n矩阵
const int N=110,mod=1e9+7;
ll n,k; 
struct Node{
    ll matrix[N][N];
    Node(){
        memset(matrix,0,sizeof(matrix));
    }
}A,ans;
Node operator*(const Node& l,const Node& r){
    Node t;
    for (int i=1;i<=n;i++){ //新矩阵行数
        for (int j=1;j<=n;j++){ //新矩阵列数
            for (int k=1;k<=n;k++){ //前列和右行
                t.matrix[i][j]=(t.matrix[i][j]+l.matrix[i][k]*r.matrix[k][j])%mod;
            }
        }
    }
    return t;
}
void quick_matrix_mi(int n,ll k){
    for (int i=1;i<=n;i++){
        ans.matrix[i][i]=1; //首先构造单位矩阵
    }
    while (k){
        if (k&1){
            ans=ans*A;
        }
        A=A*A;
        k>>=1;
    }
}

int main(){
    std::cin>>n>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            std::cin>>A.matrix[i][j];
        }
    }
    quick_matrix_mi(n,k);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            std::cout<<ans.matrix[i][j]<<' ';
        }
        std::cout<<'\n';
    }   
	return 0;
}