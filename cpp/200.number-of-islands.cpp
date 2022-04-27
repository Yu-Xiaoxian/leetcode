/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        size_t width = grid.size();
        size_t height = grid.front().size();
        int island_num = 0;
        for(size_t i = 0; i < width; i++){
            for(size_t j = 0; j < height; j++){
                if(grid[i][j] == '0'){
                    continue;
                }
                island_num++;
                queue<pair<int, int>> search_queue;
                search_queue.push({i, j});
                while(!search_queue.empty()){
                    auto pos = search_queue.front();
                    search_queue.pop();
                    size_t x = pos.first, y = pos.second;
                    if(grid[x][y] == '0'){
                        continue;
                    }
                    grid[x][y] = '0';
                    if(x > 0 && grid[x-1][y] == '1'){
                        search_queue.push({x - 1, y});
                    }
                    if(x < width - 1 && grid[x+1][y] == '1'){
                        search_queue.push({x + 1, y});
                    }
                    if(y > 0 && grid[x][y-1] == '1'){
                        search_queue.push({x, y - 1});
                    }
                    if(y < height - 1 && grid[x][y+1] == '1'){
                        search_queue.push({x, y + 1});
                    }
                }
            }
        }
        return island_num;
    }
};
// @lc code=end

int main(){
    Solution solution;
    vector<vector<char>> input;
    int result = 0;

    cout << "Example 1\n";
    input.clear();
    input.push_back({'1', '1', '0', '0', '0'});
    input.push_back({'1', '1', '0', '0', '0'});
    input.push_back({'0', '0', '1', '0', '0'});
    input.push_back({'0', '0', '0', '1', '1'});
    result = solution.numIslands(input);
    cout << result << endl;
    return 0;
}

