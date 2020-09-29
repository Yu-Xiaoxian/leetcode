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
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.front().empty())
            return false;
        
        int currRow = 0 ;
        int currCol = matrix[0].size() -1;
        
        
        while(currRow< matrix.size() &&  currCol >=0)
        {
            if(matrix[currRow][currCol]==target)
                return true;
            
            if(matrix[currRow][currCol]>target)
            {
                currCol--;
            }
            else
            {
                currRow++;
            }
        }
        
        return false;
    }
};
// @lc code=end

int main(){
    Solution solu;
    vector<vector<int>> matrix;
    int target;
    bool result;
    matrix = vector<vector<int>>({{1,3,7},{2,4,9},{5,7,11}});
    target = 13;
    result = solu.searchMatrix(matrix, target);
    cout << boolalpha << result << endl;

    matrix = vector<vector<int>>({{}});
    result = solu.searchMatrix(matrix, target);
    cout << boolalpha << result << endl;

    matrix = vector<vector<int>>({});
    result = solu.searchMatrix(matrix, target);
    cout << boolalpha << result << endl;

    matrix = vector<vector<int>>({{1,3,7},{2,4,9},{5,7,11}});
    target = 3;
    result = solu.searchMatrix(matrix, target);
    cout << boolalpha << result << endl;
    return 0;
}