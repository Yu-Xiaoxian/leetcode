/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int originColor = grid[r0][c0];
        int height = grid.size(), width;
        if(height > 0){
            width = grid[0].size();
        }
        vector<vector<char>> visited;
        visited.reserve(height);
        vector<char> tmp;
        tmp.resize(width, '0');
        for(int i = 0; i<height; i++){
            visited.push_back(tmp);
        }
        fill(grid, r0, c0, originColor, color, visited);
        return grid;
    }

    int fill(vector<vector<int>>& grid, int r, int c, int origColor, int color, vector<vector<char>>& visited){
        if(!inArena(grid, r, c)){
            return 0;
        }
        if(visited[r][c] == '1'){
            return 1;
        }
        if(grid[r][c] != origColor){
            return 0;
        }
        visited[r][c] = '1';
        int surround = fill(grid, r+1, c, origColor, color, visited)
            + fill(grid, r-1, c, origColor, color, visited)
            + fill(grid, r, c+1, origColor, color, visited)
            + fill(grid, r, c-1, origColor, color, visited);
        if(surround < 4)
            grid[r][c] = color;

        return 1;
    }

    bool inArena(const vector<vector<int>>& grid, int r, int c){
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solution;
    return 0;
}