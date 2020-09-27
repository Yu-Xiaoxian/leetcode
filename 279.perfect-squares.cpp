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
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> mem;
        mem.resize(n+1, 0);
        return numSquares(n, &mem);
    }

    int numSquares(int n, vector<int>* pmem){
        int root = floor(sqrt(n));
        if(root * root == n){
            (*pmem)[n] = 1;
            return 1;
        }
        int min_num = numeric_limits<int>::max();
        for(int i = 1; i <= root; i++){
            int index = n - i*i;
            int tmp_num = 0;
            if(pmem->at(index) != 0){
                tmp_num = 1 + pmem->at(index);
            }
            else{
                tmp_num = 1 + numSquares(index, pmem);
                (*pmem)[index] = tmp_num - 1;
            }
            min_num = min(tmp_num, min_num);
        }
        return min_num;
    }
};
// @lc code=end

int main(){
    Solution solu;
    int result = 0;
    result = solu.numSquares(12);
    cout << result << endl;
    result = solu.numSquares(13);
    cout << result << endl;
    result = solu.numSquares(1);
    cout << result << endl;
    return 0;
}

