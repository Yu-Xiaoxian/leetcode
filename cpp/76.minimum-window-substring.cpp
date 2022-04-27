/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

// @lc code=start
class Solution {
public:
    unordered_map<char, int> need;       
    unordered_map<char, int> curr;
    string minWindow(string s, string t) {
        need.clear();
        curr.clear();
        int start = 0, end = 0, res = 0, res_len = INT_MAX;
        for(auto ch : t){
            need[ch] += 1;
        }
        while(end < s.size()){
            char c1 = s[end];
            if(need.count(c1))
                curr[c1]++;
            end++;
            while(isMatched()){
                int curr_len = end - start;
                if(res_len > curr_len){
                    res = start;
                    res_len = curr_len;
                }
                char c2 = s[start];
                if(need.count(c2))
                    curr[c2]--;
                start++;
            }
        }

        return res_len == INT_MAX? "" : s.substr(res, res_len);
    }

    bool isMatched(){
        for(auto it = need.begin(); it != need.end(); it++){
            if(it->second > curr[it->first]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solution;

    cout << "Example 1\n";
    return 0;
}
