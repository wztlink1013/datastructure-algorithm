#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // 重载
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<int> result = {};
        vector<int> inorderTraversal(TreeNode* root) {
            if (root) {
                inorderTraversal(root->left);
                result.push_back(root->val);
                inorderTraversal(root->right);
                return result;
            } else {
                return result;
            }
        }
};

int main () {
    // 初始化一棵二叉树
    TreeNode *node_1 = new TreeNode;
    TreeNode *node_2 = new TreeNode;
    TreeNode *node_3 = new TreeNode;
    node_1->val = 1;
    node_1->right = node_2;
    node_2->val = 2;
    node_2->left = node_3;
    node_3->val = 3;

    // 将其中序遍历
    Solution x;
    for (auto i : x.inorderTraversal(node_1))
        cout << i << " ";
}
