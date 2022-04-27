/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()){
            while(s[i] != t[j] && j < t.size()){
                j++;
            }
            if(j == t.size() || s[i] != t[j]){
                return false;
            }
            i++;
        }

        return true;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solution;
    string s, t;
    bool res;

    cout << "Example 1\n";
    s = "abc";
    t = "ahbgdc";
    res = solution.isSubsequence(s, t);
    printf("%s\n", res? "true":"false");

    cout << "Example 2\n";
    s = "axc";
    t = "ahbgdc";
    res = solution.isSubsequence(s, t);
    printf("%s\n", res? "true":"false");

    cout << "Example 3\n";
    s = "axc";
    t = "";
    res = solution.isSubsequence(s, t);
    printf("%s\n", res? "true":"false");
    return 0;
}