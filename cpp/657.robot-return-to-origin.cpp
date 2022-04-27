/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto& ch : moves){
            switch(ch){
                case 'L':
                    x -= 1;
                    break;
                case 'R':
                    x += 1;
                    break;
                case 'U':
                    y += 1;
                    break;
                case 'D':
                    y -= 1;
                    break;
                default:
                    break;
            }
        }
        return x == 0 && y == 0? true : false;
    }
};
// @lc code=end

int main(){
    return 0;
}
