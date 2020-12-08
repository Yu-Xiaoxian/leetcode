/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */
#include <iostream>
#include <unordered_map>
#include <memory.h>

using namespace std;

// @lc code=start
class Solution {
public:
  unordered_map<char, int> window;
  int longestSubstring(string s, int k) {
    int result = 0, map[26] = {0};
    int max_unique = maxUniqueLetters(s);
    for(int curr_unique = 1; curr_unique <= max_unique; curr_unique++){
      memset(map, 0, sizeof(map));
      int left = 0, right = 0, unique = 0, cntatleastk = 0, idx = 0;
      while(right < s.size()){
        if(unique <= curr_unique){
          idx = s[right] - 'a';
          if(map[idx] == 0){
            unique++;
          }
          map[idx]++;
          if(map[idx] == k) {
            cntatleastk++;
          }
          right++;
        }
        else{
          idx = s[left] - 'a';
          if(map[idx] == k){
            cntatleastk--;
          }
          map[idx]--;
          if(map[idx] == 0){
            unique--;
          }
          left++;
        }
        if(unique == curr_unique && cntatleastk == unique){
          result = max(result, right - left);
        }
      }
    }
    return result;
  }

  int maxUniqueLetters(const string& s){
      bool map[26] = {false};
      int max_unique = 0;
      for(const auto ch : s){
          if(!map[ch - 'a']){
              max_unique++;
              map[ch - 'a'] = true;
          }
      }
      return max_unique;
  }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solution;
    string str;
    int result = 0, expect = 0, k = 0;

    cout << "Example 1\n";
    str = "aaabb";
    k = 3;
    expect = 3;
    result = solution.longestSubstring(str, k);
    cout << "expect:\t" << expect << "\t" << "result:\t" << result << endl;
    return 0;
}

