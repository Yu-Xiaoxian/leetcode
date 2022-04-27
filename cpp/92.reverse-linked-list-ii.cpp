/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */
#include <iostream>

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int index = 0;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* curr = dummy;
        ListNode* prev = nullptr, *r_head = nullptr, *tmp = nullptr;
        while(curr != nullptr && index <= n){
            if(index < m){
                r_head = curr;
                prev = curr;
                curr = curr->next;
            }
            else{
                tmp = curr;
                curr = curr->next;
                tmp->next = prev;
                prev = tmp;
            }
            index++;
        }
        r_head->next->next = curr;
        r_head->next = prev;

        return dummy->next;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solut;
    
    cout << "Example 1\n";
    return 0;
}
