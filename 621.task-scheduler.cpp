/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_counts;
        task_counts.resize(26);
        for(auto t: tasks){
            task_counts[static_cast<int>(t - 'A')]++; 
        }
        sort(task_counts.begin(), task_counts.end());
        int i = 25;
        while(i>=0 && task_counts[i] == task_counts[25]){
            i--;
        }
        return max(static_cast<int>(tasks.size()), (task_counts[25] - 1) * (n+1) + (25 -i));
    }
};
// @lc code=end

int main(){
    return 0;
}
