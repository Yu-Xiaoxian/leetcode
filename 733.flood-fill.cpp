/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int origColor = image[sr][sc];
        fill(image, sr, sc, origColor, newColor);
        return image;
    }

    void fill(vector<vector<int>> &image, int sr, int sc, int origColor, int newColor)
    {
        if (!inArena(image, sr, sc))
        {
            return;
        }
        if (image[sr][sc] != origColor)
        {
            return;
        }
        if (image[sr][sc] == -1)
        {
            return;
        }
        image[sr][sc] = -1;
        fill(image, sr+1, sc, origColor, newColor);
        fill(image, sr-1, sc, origColor, newColor);
        fill(image, sr, sc+1, origColor, newColor);
        fill(image, sr, sc-1, origColor, newColor);
        image[sr][sc] = newColor;
    }

    bool inArena(const vector<vector<int>> &image, int sr, int sc)
    {
        return (sr >= 0 && sr < image.size() && sc >= 0 && sc < image.front().size());
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    Solution solution;
    vector<vector<int>> input;
    int sr = 0, sc = 0, newColor;
    vector<vector<int>> result;
    // Example 1
    result = solution.floodFill(input, sr, sc, newColor);
    std::cout << result.size() << "\n";
    return 0;
}