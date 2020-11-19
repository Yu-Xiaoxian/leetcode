/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /***************************/
        // priority_queue solution
        std::priority_queue<int> pq;
        for(auto n : nums){
            pq.push(n);
        }
        while(k > 1){
            pq.pop();
            k--;
        }
        return pq.top();


        /********************/
        // Quick Sort solution
        // int begin = 0;
        // int end = nums.size() - 1;
        // while(begin < end){
        //     int p = partition(nums, begin, end);
        //     if(p == k-1){
        //         break;
        //     } else if(p < k-1){
        //         begin = p+1;
        //     } else if(p > k-1){
        //         end = p-1;
        //     }
        // }
        // return nums[k-1];
    }

    int partition(vector<int>& nums, int begin, int end){
        int pivot = nums[end];
        int p = begin;
        for(int i = begin; i< end; i++){
            if(nums[i] > pivot){
                int tmp = nums[i];
                nums[i] = nums[p];
                nums[p] = tmp;
                p++;
            }
        }
        int tmp = nums[p];
        nums[p] = nums[end];
        nums[end] = tmp;
        return p;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solu;
    return 0;
}

