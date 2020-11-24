/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *curr, *next;
        vector<int> result;
        curr = head;
        while(curr != nullptr){
            next = curr->next;
            while(next != nullptr){
                if(next->val > curr->val){
                    break;
                }
                next = next->next;
            }
            result.push_back(next == nullptr? 0 : next->val);
            curr = curr->next;
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solution;

    cout << "Example 1\n";
    return 0;
}