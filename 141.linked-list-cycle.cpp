/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while(fast != nullptr && slow != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr){
                fast = fast->next;
            }
            else{
                return false;
            }
            if(fast == slow){
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solu;
    solu;

    cout << "Example 1\n";
    return 0;
}

