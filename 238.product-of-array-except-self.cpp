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
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()){
            return result;
        }
        vector<int> pre_product, post_product;
        int len = nums.size();
        pre_product.resize(len + 1);
        post_product.resize(len + 1);
        result.reserve(len);
        pre_product[0] = 1;
        post_product[len] = 1;
        for(int i = 0; i < len; i++){
            pre_product[i+1] = pre_product[i] * nums[i];
            post_product[len - i -1] = post_product[len - i] * nums[len - i - 1];
        }
        for(int i = 0; i < len; i++){
            result.push_back(pre_product[i] * post_product[i+1]);
        }
        return result;
    }
};
// @lc code=end

int main(){
    Solution solu;
    vector<int> nums;
    vector<int> result;
    // ex 0
    result = solu.productExceptSelf(nums);
    for(auto n : result){
        cout << n << " ";
    }
    cout << endl;
    // ex 1
    nums = vector<int>({1,2,3,4});
    result = solu.productExceptSelf(nums);
    for(auto n : result){
        cout << n << " ";
    }
    cout << endl;
    // ex 2
    nums = vector<int>({0,0});
    result = solu.productExceptSelf(nums);
    for(auto n : result){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

