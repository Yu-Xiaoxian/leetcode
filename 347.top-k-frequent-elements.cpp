/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_map;
        for(auto num : nums){
            auto it = nums_map.find(num);
            if(it == nums_map.end()){
                nums_map.insert({num, 1});
            }
            else{
                it->second+=1;
            }
        }

        vector<int> result;
        for(int i = 0; i<k; i++){
            auto max = nums_map.begin();
            auto it = nums_map.begin();
            while(it != nums_map.end()){
                if(it->second > max->second){
                    max = it;
                }
                it++;
            }
            result.push_back(max->first);
            nums_map.erase(max);
        }

        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums;
    vector<int> result;
    int k = 2;
    nums = {1,1,1,2,2,3};
    result = s.topKFrequent(nums, k);
    for(auto num : result){
        cout << num << " ";
    }
    cout << endl;

    k = 1;
    nums = {1};
    result = s.topKFrequent(nums, k);
    for(auto num : result){
        cout << num << " ";
    }
    cout << endl;

    k = 3;
    nums = {3,3,3,4,4,5,5,5,1,1,1,1};
    result = s.topKFrequent(nums, k);
    for(auto num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

