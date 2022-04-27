/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;       
        slow = head;
        fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                break;
            }
        }
        if(fast != nullptr && fast->next != nullptr){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }

        return nullptr;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solut;

    cout << "Example 1\n";
    return 0;
}
