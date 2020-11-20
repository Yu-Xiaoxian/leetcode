/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int lo = 0, hi = s.size() - 1;
        char tmp;
        while(lo < hi){
            tmp = s[lo];
            s[lo] = s[hi];
            s[hi] = tmp;
            lo++;
            hi--;
        }
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solut;
    vector<char> input;
    vector<char> result;

    cout << "Example 1 \n";
    input = vector<char>({'h','e','l','l','o'});
    solut.reverseString(input);
    return 0;
}
