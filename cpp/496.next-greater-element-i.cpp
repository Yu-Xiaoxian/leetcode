/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        result.reserve(nums1.size());
        for(auto n : nums1){
            int i = 0;
            while(i < nums2.size()){
                if(nums2[i] == n){
                    break;
                }
                i++;
            }
            while(i < nums2.size()){
                if(nums2[i] > n){
                    break;
                }
                i++;
            }
            result.push_back(i == nums2.size()? -1 : nums2[i]);
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