#include <bits/stdc++.h>


#if 0
int next[N];
char s1[N],s2[N];
std::vector<int> vis;
std::string ss1,ss2;
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
int mx=0;
void match(const char s1[],const char s2[],int n1,int n2){
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
            mx=std::max(mx,i);
        }
    }
}
int main(){
    std::string str;
    while (std::cin>>str){
        if (str=="."){
            break;
        }
        vec.push_back(str);
    }
    std::cin>>ss1;
    vis.resize(ss1.size());
    std::fill(vis.begin(),vis.end(),0);

    strcpy(s1+1,ss1.c_str());
    int n1=strlen(s1+1);
    getNext(s1,n1);
    
    for (auto& x:vec){
        strcpy(s2+1,x.c_str());
        int n2=strlen(s2+1);
        match(s1,s2,n1,n2);
        std::cout<<'\n';
    }

    std::cout<<mx;
	return 0;
}

#else 

//AC自动机
const int N=1e6+10;
std::vector<std::string> vec;
std::string dst;
int next[N];   //存节点i的回跳边的终点: 四边形
int tree[N][26]; //存节点i的树边的终点或者是转移边的终点：直线或三角形
int cnt[N];
int idx=0;
void insert(std::string s){
    int p=0;
    for (auto& x:s){
        int j=x-'A';
        if (!tree[p][j]){
            tree[p][j]=++idx;
        }
        p=tree[p][j];
    }   
    cnt[p]++;
}
void build(){
    std::queue<char> q;
    for (int i=0;i<26;i++){
        if (tree[0][i]){ //如果存在某一个字母节点
            q.push(tree[0][i]); //则入队，表示以某个字母开始
        }
    }
    while (!q.empty()){
        int p=q.front();
        q.pop();
        for (int i=0;i<26;i++){
            int j=tree[p][i];//当前儿子节点
            if (j){
                //如果儿子存在，则爹帮儿子建回跳边: 当前节点的父节点的回跳边的所指儿子
                next[j]=tree[next[p]][i];
                q.push(j);
            }
            else{
                //如果儿子不存在，则爹自建转移边: 当前节点的回跳边所指儿子
                tree[p][i]=tree[next[p]][i];
            }
        }
    }
}
int query(std::string s){
    int ans=0;
    for (int k=0,p=0;k<s.size();k++){
        p=tree[p][s[k]-'A'];
        for (int j=p;j&&~cnt[j];j=next[j]){ //~表示按位取反 -1则1111 -> 0000
            ans+=cnt[j];
            cnt[j]=-1; //答案只出现一次
        }
    }
    return ans;
}

int main(){
    std::string s;
    while (std::cin>>s){
        if (s=="."){
            break;
        }
        vec.push_back(s);
    }
    std::cin>>dst;
    for (auto& x:vec){
        insert(x);
    }
    build();
    std::cout<<query("ABC");

    return 0;
}
#endif

