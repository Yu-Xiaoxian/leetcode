/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */
#include <string>
#include <stack>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string result;
        stack<int> int_stack;
        stack<string> str_stack;
        int i = 0;
        while(i < s.size()){
            if(isdigit(s[i])){
                string num_s;
                while(isdigit(s[i])){
                    num_s.push_back(s[i]);
                    i++;
                }
                int n = stoi(num_s);
                int_stack.push(n);
            }
            else if(isalpha(s[i])){
                result.push_back(s[i++]);
            }
            else if(s[i] == '['){
                str_stack.push(result);
                result.clear();
                i++;
            }
            else if(s[i] == ']'){
                int n = int_stack.top();
                int_stack.pop();
                string str = str_stack.top();
                str_stack.pop();
                while(n > 0){
                    str.append(result);
                    n--;
                }
                result.swap(str);
                // result = str;
                i++;
            }
        }

        return result;
    }
};
// @lc code=end
int main(){
    Solution s;
    string str("3[abc]");
    auto result = s.decodeString(str);
    cout << result << endl << endl;

    str = "abc3[cd]xyz";
    result = s.decodeString(str);
    cout << result << endl<< endl;

    str = "2[abc]3[cd]ef";
    result = s.decodeString(str);
    cout << result << endl<< endl;

    str = "3[a2[c]]";
    result = s.decodeString(str);
    cout << result << endl;
    return 0;
}
