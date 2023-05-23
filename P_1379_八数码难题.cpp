#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;
#define l std::cout<<'\n'
#define io std::ios::sync_with_stdio(false),std::cin.tie(nullptr);

const int N=1e5+10,K=3;
int n,m;
std::string src;
std::unordered_map<std::string,int> ump;
const int dx[4]{-1,1,0,0},dy[4]{0,0,-1,1};
int bfs(){
    std::queue<std::string> q;
    std::string dst="123804765";
    q.push(src);
    while (!q.empty()){
        std::string s=q.front();
        q.pop();
        if (s==dst){
            return ump[s]; //达到目标
        }
        int dis=ump[s]; //当前的移动次数
        //0是自由的，考虑移动0的位置
        int pos=s.find('0');
        //一维转换为二维
        int x=pos/K,y=pos%K;
        for (int i=0;i<4;i++){
            int cx=x+dx[i],cy=y+dy[i];
            if (cx>=0 && cx<K && cy>=0 && cy<K){
                //模拟0移动到四个位置上
                std::swap(s[cx*K+cy],s[pos]);
                if (!ump.count(s)){
                    ump[s]=dis+1;
                    q.push(s);
                }
                std::swap(s[cx*K+cy],s[pos]);
            }
        }
    }
    return 0;
}
signed main(){
   std::cin>>src;
    std::cout<<bfs();
    return 0;
}