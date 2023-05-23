#include <bits/stdc++.h>

const int N = 1e5 + 10;
int n, m;
int nums[N];  //节点的初始数值
std::vector<int> vec[N];
int fa[N], son[N], top[N], sz[N], dep[N];
int id[N], val[N]; //id记录转为线段树之后的节点序号，val记录节点的值
int cnt,e;
struct Node {
    int sum;
    int tag;
}tree[N << 2];
struct Edge{
    int to,next;
}edge[N<<2];
int head[N];
void add_edge(int u,int v){
    edge[++e].to=v;
    edge[e].next=head[u];
    head[u]=e;
}
void push_up(int i) {
    tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
}
void push_down(int i, int pl, int pr) {
    if (tree[i].tag) {
        int mid = pl + pr >> 1;
        tree[i << 1].tag += tree[i].tag;
        tree[i << 1].sum += (mid - pl + 1) * tree[i].tag;
        tree[i << 1 | 1].tag += tree[i].tag;
        tree[i << 1 | 1].sum += (pr - (mid + 1) + 1) * tree[i].tag;
        tree[i].tag = 0;
    }
}
void build(int i, int pl, int pr) {
    if (pl == pr) {
        tree[i].sum = 0;
        return;
    }
    int mid = pl + pr >> 1;
    build(i << 1, pl, mid);
    build(i << 1 | 1, mid + 1, pr);
    push_up(i);
}
void update(int i, int pl, int pr, int L, int R, int k) {
    if (L <= pl && pr <= R) {
        tree[i].sum += (pr - pl + 1) * k;
        tree[i].tag += k;
        return;
    }
    push_down(i, pl, pr);
    int mid = pl + pr >> 1;
    if (L <= mid) update(i << 1, pl, mid, L, R, k);
    if (R > mid) update(i << 1 | 1, mid + 1, pr, L, R, k);
    push_up(i);
}
int query(int i, int pl, int pr, int L, int R) {
    if (L <= pl && pr <= R) {
        return tree[i].sum;
    }
    int ans = 0;
    push_down(i, pl, pr);
    int mid = pl + pr >> 1;
    if (L <= mid) ans = ans + query(i << 1, pl, mid, L, R);
    if (R > mid) ans = ans + query(i << 1 | 1, mid + 1, pr, L, R);
    return ans;
}
void dfs1(int now, int father) {
    //树链
    fa[now] = father;
    dep[now] = dep[father] + 1;
    sz[now] = 1;
    //遍历所有now的子节点
    for (int i=head[now];i;i=edge[i].next){
        int x=edge[i].to;
        if (x == father) {
            continue;
        }
        dfs1(x,now);
        sz[now] += sz[x];
        if (sz[son[now]]<sz[x]){
            son[now]=x;
        }
    }
}
void dfs2(int now, int t) {
    top[now] = t;
    //线段树操作--------------------
    id[now] = ++cnt;//节点编号: 优先给重孩子编号
    val[cnt] = nums[now];//节点的权值
    //----------------------------
    if (!son[now]) {
        return;
    }
    dfs2(son[now], t);
    //对轻孩子进行操作
    for (int i=head[now];i;i=edge[i].next){
        int x=edge[i].to;
        //不能等于父节点或者是重孩子节点
        if (x == fa[now] || x == son[now]) {
            continue;
        }
        dfs2(x, x);
    }
}
int find_range(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            std::swap(x, y);
        }
        ans = ans + query(1, 1, n, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (x==y){
        return ans;
    }
    if (dep[x] < dep[y]) {
        std::swap(x, y);
    }
    ans = ans + query(1, 1, n, id[y]+1, id[x]);
    return ans;
}
void update_range(int x, int y, int k=1) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            std::swap(x, y);
        }
        update(1, 1, n, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if (x==y){
        return;
    }
    if (dep[x] < dep[y]) {
        std::swap(x, y);
    }
    update(1, 1, n, id[y]+1, id[x], k);
}
signed main() {
    std::cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        char op;
        int  x, y;
        std::cin >> op>>x>>y;
        if (op == 'P') {
            update_range(x, y);
        }
        else if (op =='Q'){
            std::cout << find_range(x,y) << '\n';
        }
    }
    return 0;
}