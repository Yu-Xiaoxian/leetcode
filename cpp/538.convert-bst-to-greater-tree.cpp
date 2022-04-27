/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }

    int sum = 0;
    void traverse(TreeNode* root){
        if(root == nullptr){
            return;
        }
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solution;

    cout << "Example 1\n";
    return 0;
}