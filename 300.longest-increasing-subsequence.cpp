/*
 *  Copyright [2020] [Yu Xiaoxian]
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int> nums) {
        if(nums.empty()){
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] = dp[i] + 1;
        }

        int max_len = 0;
        for(auto len : dp){
            max_len = max(len, max_len);
        }
        return max_len;
    }
};
// @lc code=end

int main(){
    Solution solut;
    vector<int> nums({10,9,2,5,3,7,101,18});
    auto result = solut.lengthOfLIS(nums);
    cout << result << endl;
    return 0;
}

