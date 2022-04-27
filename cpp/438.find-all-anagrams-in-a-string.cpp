/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for(auto ch : p) need[ch]++;
        int start = 0, end = 0;

        int matched = 0;
        while(end < s.size()){
            char c1 = s[end];
            if(need.count(c1)){
                window[c1]++;
                if(need[c1] == window[c1]){
                    matched++;
                }
            }
            end++;
            while(matched == need.size()){
                if(end - start == p.length())
                    result.push_back(start);
                char c2 = s[start];
                if(need.count(c2)){
                    window[c2]--;
                    if(need[c2] > window[c2]){
                        matched--;
                    }
                }
                start++;
            }
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
