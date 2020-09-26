/*
 *  Copyright [2020] [Yu Xiaoxian]
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

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
