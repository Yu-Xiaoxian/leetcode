/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

#include <iostream>
#include <deque>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = root, *curr = root;
        bool p_found = false, q_found = false;
        while(true){
            p_found = false;
            q_found = false;
            isCommonAncestor(curr->left, p, q, p_found, q_found);
            if(p_found && q_found){
                result = curr->left;
                curr = result;
                continue;
            }
            p_found = false;
            q_found = false;
            isCommonAncestor(curr->right, p, q, p_found, q_found);
            if(p_found && q_found){
                result = curr->right;
                curr = result;
                continue;
            }
            break;
        }
        return result;
    }

    void isCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool &p_found, bool &q_found){
        if(root == nullptr){
            return;
        }
        if(root == p){
            p_found = true;
        }
        else if(root == q){
            q_found = true;
        }
        isCommonAncestor(root->left, p, q, p_found, q_found);
        isCommonAncestor(root->right, p, q, p_found, q_found);
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution s;
    s.lowestCommonAncestor(nullptr, nullptr, nullptr);
    return 0;
}

