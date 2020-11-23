/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int max_len = 0;
        int start = 0, end = 0;
        while(end < s.size()){
            char c1 = s[end];
            window[c1]++;
            end++;
            // cout << "Count " << window[c1] << " " << window.count(c1) << endl;
            while(window[c1] > 1){
                char c2 = s[start];
                window[c2]--;
                start++;
                // cout << "Start " << start << endl;
            }
            max_len = max(max_len, end - start);
        }
        return max_len;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solution;
    string input;
    int result = 0;
    int expected = 0;

    cout << "Example 1\n";
    input = "bbbbb";
    expected = 1;
    result = solution.lengthOfLongestSubstring(input);
    cout << "Result " << result << "\tExpected " << expected << endl;
    return 0;
}
