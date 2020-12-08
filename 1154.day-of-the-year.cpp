/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear(string date) {
        int result = 0;
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        for(int i = 0; i < month - 1; i++){
            if(i == 1 && year % 4 == 0 && year % 100 != 0){
                result += 29;
            }
            else{
                result += dayOfMonth[i];
            }
        }
        result += day;

        return result;
    }
};
// @lc code=end

int main(){
    return 0;
}
