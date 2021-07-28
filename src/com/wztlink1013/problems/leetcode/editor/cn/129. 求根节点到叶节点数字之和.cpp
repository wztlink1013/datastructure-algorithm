#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode* root, int prevSum) {
        if (root == nullptr) {
            return 0;
        }
        int sum = prevSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};


int main() {
    // 初始化一个测试用例
    TreeNode* node_1 = new TreeNode;
    TreeNode* node_2 = new TreeNode;
    TreeNode* node_3 = new TreeNode;
    TreeNode* node_4 = new TreeNode;
    TreeNode* node_5 = new TreeNode;
    node_1->val = 4;
    node_1->left = node_2;
    node_1->right = node_3;
    node_3->val = 0;
    node_2->val = 9;
    node_2->left = node_4;
    node_2->right = node_5;
    node_4->val = 5;
    node_5->val = 1;

    Solution result;
    cout<< result.sumNumbers(node_1);
}