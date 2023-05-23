#include <bits/stdc++.h>

const int N=1e6+10;
int next[N];
char s1[N],s2[N];
void getNext(char s[],int n){
    //找出模式串的相等前后缀字符串的最长长度
    next[1]=0;
    for (int i=2,j=0;i<=n;i++){
        while (j && s[i]!=s[j+1]){
            j=next[j]; //往回退，寻找前面最大匹配的位置
        }
        if (s[i]==s[j+1]){
            j++; //当前匹配，j移动
        }
        next[i]=j; //记录当前位置的最长匹配长度
    }
}
void match(char s1[],char s2[],int n1,int n2){
    //把模式串s2与主串s1进行匹配
    for (int i=1,j=0;i<=n1;i++){
        while (j && s1[i]!=s2[j+1]){
            j=next[j];
        }
        if (s1[i]==s2[j+1]){
            j++;
        }
        if (j==n2){
            std::cout<<i-n2+1<<'\n';
        }
    }
}
int main(){
    std::cin>>s1+1>>s2+1;
    int len1=strlen(s1+1),len2=strlen(s2+1);
    getNext(s2,len2);
    match(s1,s2,len1,len2);
    for (int i=1;i<=len2;i++){
        std::cout<<next[i]<<' ';
    }
	return 0;
}