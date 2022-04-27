/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

#include <iostream>
#include <queue>
#include <cmath>

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
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int result = 0;
        int height = depth(root);
        int right_height = depth(root->right);
        if(right_height < height - 1){
            result += countNodes(root->left);
            result += pow(2, right_height + 1) - 1;
            result++;
        }
        else{
            result += pow(2, right_height + 1) - 1;
            result += countNodes(root->right);
            result++;
        }
        return result;
    }

    int depth(TreeNode* root){
        TreeNode* curr = root;
        int depth = -1;
        while(curr != nullptr){
            curr = curr->left;
            depth++;
        }
        return depth;
    }
};
// @lc code=end

int main(){
    return 0;
}
