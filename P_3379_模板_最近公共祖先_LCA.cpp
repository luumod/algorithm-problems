#include <bits/stdc++.h>

const int N = 5e5 + 10;
#if 0
/*
1. 倍增算法：深搜打表 跳跃查询
*/
int n, m, s;
std::vector<int> vec[N];
int depth[N], fa[N][25];
void init(int now, int father) {
    depth[now] = depth[father] + 1;
    fa[now][0] = father;
    for (int i = 1; i <= 20; i++) {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    }
    for (auto& x : vec[now]) {
        if (x != father) {
            init(x, now);
        }
    }
}
int lca(int x, int y) {
    //让x的深度最大
    if (depth[x] < depth[y]) {
        std::swap(x, y);
    }
    for (int i = 20; i >= 0; i--) {
        if (depth[fa[x][i]] >= depth[y]) {
            x = fa[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 20; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main() {
    std::cin >> n >> m >> s;
    vec[0].push_back(s);
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    init(s, 0);
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        printf("%d\n", lca(x, y));
    }
    return 0;
}

#elif 0
/*
2. targan算法：深搜，入标记，离查询
*/
int n, m, s;
std::vector<int> vec[N];
std::vector<std::pair<int, int>> query[N];
int parent[N + 10]; //并查集
bool vis[N]; //标记访问
int ans[N]; //答案数组
int find(int now){
    if (now!=parent[now]){
        return parent[now]=find(parent[now]);
    }
    return now;
}
void targan(int now) {
    vis[now] = true;
    for (auto& x : vec[now]) {
        if (!vis[x]) {
            targan(x);
            parent[x] = now; //标记父节点rr为now
        }
    }
    for (auto& x : query[now]) {
        int to = x.first, i = x.second;
        if (vis[to]) { //必须是已经访问过的点
            ans[i] = find(to); //并查集中查询并且维护
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        query[x].push_back({ y,i });
        query[y].push_back({ x,i });
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    targan(s);
    for (int i = 1; i <= m; i++) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}
#elif 1

/*
3. 树链剖分
*/
int n,m,s;
std::vector<int> vec[N];
int fa[N],son[N],sz[N],top[N],dep[N]; //标记父节点；标记重孩子；标记节点数；标记重链起点；标记当前深度
//1. dfs1求fa dep sz son数组
void dfs1(int now,int father){
    fa[now]=father;
    dep[now]=dep[father]+1;
    sz[now]=1;
    for (auto& x:vec[now]){
        if (x!=father){
            dfs1(x,now);
            sz[now]+=sz[x];
            //确定当前点的重孩子
            if (sz[son[now]]<sz[x]){
                son[now]=x;   
            }
        }
    }
}
//2. dfs2求top数组
void dfs2(int now,int t){
    top[now]=t;
    //回溯：叶子节点没有重孩子
    if (!son[now]){
        return;
    }
    dfs2(son[now],t);
    //遍历轻儿子
    for (auto& x:vec[now]){
        if (x==fa[now] || x==son[now]){
            continue;
        }
        dfs2(x,x); //叶子节点的重链起点为其自身
    }
}
int query(int x,int y){
    while (top[x]!=top[y]){
        //指定x为较深的那一个，类似于倍增的跳跃
        if (dep[top[x]]<dep[top[y]]){
            std::swap(x,y);
        }
        x=fa[top[x]]; //跳跃到重链起点的父节点位置
    }
    return dep[x]<dep[y]?x:y; //返回深度较小的那一个
}
int main() {
    std::cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs1(s,0);
    dfs2(s,s);
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        printf("%d\n",query(x,y));
    }
    return 0;
}
#endif