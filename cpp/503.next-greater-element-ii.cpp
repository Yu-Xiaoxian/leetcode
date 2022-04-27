/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result;       
        result.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int j = i+1;
            bool find = false;
            while(j < nums.size()){
                if(nums[j] > nums[i]){
                    find = true;
                    break;
                }
                j++;
            }
            if(!find) j = 0;
            while(j < i && !find){
                if(nums[j] > nums[i]){
                    find = true;
                    break;
                }
                j++;
            }
            result.push_back(find? nums[j] : -1);
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