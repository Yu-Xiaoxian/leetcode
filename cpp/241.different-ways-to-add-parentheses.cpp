/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i = 0; i < input.size(); i++){
            char c = input[i];
            if(c == '-' || c == '+' || c == '*'){
                auto vec1 = diffWaysToCompute(input.substr(0, i));
                auto vec2 = diffWaysToCompute(input.substr(i+1));
                for(auto a : vec1){
                    for(auto b : vec2){
                        if(c == '-'){
                            result.push_back(a - b);
                        }
                        else if(c == '+'){
                            result.push_back(a + b);
                        }
                        else if(c == '*'){
                            result.push_back(a * b);
                        }
                    }
                }
            }
        }

        if(result.empty()){
            result.push_back(stoi(input));
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