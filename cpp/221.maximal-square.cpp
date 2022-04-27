/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp;
        int height = matrix.size(), width = 0;
        if(height > 0){
            width = matrix.front().size();
        }
        vector<int> row(width+1, 0);
        for(int i = 0; i <= height; i++){
            dp.push_back(row);
        }

        for(int r = 1; r <= height; r++){
            for(int c = 1; c <= width; c++){
                if(matrix[r-1][c-1] == '1'){
                    dp[r][c] = min(dp[r-1][c-1], min(dp[r-1][c], dp[r][c-1])) + 1;
                }
            }
        }

        int max_square = 0;
        for(int r = 1; r <= height; r++){
            for(int c = 1; c <= width; c++){
                max_square = max(dp[r][c], max_square);
            }
        }
        return max_square * max_square;
    }
};
// @lc code=end

int main(int argc, char** argv){
    return 0;
}