/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i_10 = 0, dp_i_11 = numeric_limits<int>::min();
        int dp_i_20 = 0, dp_i_21 = numeric_limits<int>::min();
        for(int i = 0; i<prices.size(); i++){
            dp_i_20 = max(dp_i_20, dp_i_21 + prices[i]);
            dp_i_21 = max(dp_i_21, dp_i_10 - prices[i]);
            dp_i_10 = max(dp_i_10, dp_i_11 + prices[i]);
            dp_i_11 = max(dp_i_11, -prices[i]);
        }
        return dp_i_20;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solution;

    vector<int> prices;
    int result;

    // Example 1
    prices = vector<int>({3,3,5,0,0,3,1,4});
    result = solution.maxProfit(prices);
    cout << result << "\n";
    return 0;
}