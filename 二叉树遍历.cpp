#include <bits/stdc++.h>

struct TreeNode {
    TreeNode(char c = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) :c(c), left(left), right(right) {}
    char c;
    TreeNode* left, * right;
};
TreeNode* tree;
std::string s;
void dfs(TreeNode*& node, int& i) {
    if (s[i] == '#') {
        return;
    }
    TreeNode* pNew = new TreeNode{ s[i] };
    node = pNew;
    dfs(node->left, ++i);
    dfs(node->right, ++i);
}
void travel(TreeNode* root) {
    if (root==nullptr){
        return ;
    }
    travel(root->left);
    std::cout << root->c << ' ';
    travel(root->right);
}
void solve() {
    tree = new TreeNode;
    int i = 0;
    dfs(tree, i);
    travel(tree);
}
int main() {
    std::cin >> s;
    solve();

    return 0;
}