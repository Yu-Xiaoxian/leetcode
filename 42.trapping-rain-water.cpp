/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int vol = 0;
        std::stack<int> left_height;
        int itr = 0;
        left_height.push(itr);
        ++itr;
        while (!left_height.empty() && itr < height.size()) {
            int left_index = left_height.top();
            while (height[itr] > height[left_index]) {
                left_height.pop();
                if (!left_height.empty()) {
                    int left_index_2 = left_height.top();
                    int depth = std::min(height[itr], height[left_index_2]);
                    vol += (itr - left_index_2 - 1) * (depth - height[left_index]);
                    left_index = left_height.top();
                } else {
                    break;
                }
            }
            left_height.push(itr);
            ++itr;
        }
        return vol;
    }
};
// @lc code=end

int main(int argc, char** argv) {
    std::vector<int> height;
    int result = 0;
    int expect = 0;
    Solution s;

    // Test 0
    result = s.trap(height);
    std::cout << "=== Test 0 ===\n";
    std::cout << "Expect " << expect << std::endl;
    std::cout << "Result " << result << std::endl;

    // Test 1
    std::cout << "=== Test 1 ===\n";
    height = std::vector<int>({0,1,0,2,1,0,1,3,2,1,2,1});
    expect = 6;
    result = s.trap(height);
    std::cout << "Expect " << expect << std::endl;
    std::cout << "Result " << result << std::endl;

    // Test 2
    std::cout << "=== Test 2 ===\n";
    height = std::vector<int>({4,2,0,3,2,5});
    expect = 9;
    result = s.trap(height);
    std::cout << "Expect " << expect << std::endl;
    std::cout << "Result " << result << std::endl;
    return 0;
}