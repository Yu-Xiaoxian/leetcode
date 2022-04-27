/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */
#include <vector>
#include <limits>
#include <set>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int X1 = 0;
        int Y1 = 0;
        int X2 = 0;
        int Y2 = 0;
        bool first = true;
        int area = 0;
        set<pair<int, int>> points;       

        for(auto rect : rectangles){
            int x1 = rect[0];
            int y1 = rect[1];
            int x2 = rect[2];
            int y2 = rect[3];
            if(first){
                X1 = x1;
                X2 = x2;
                Y1 = y1;
                Y2 = y2;
                first = false;
            }
            else{
                X1 = min(X1, x1);
                Y1 = min(Y1, y1);
                X2 = max(X2, x2);
                Y2 = max(Y2, y2);
            }
            
            area += (x2 - x1) * (y2 - y1);
            vector<pair<int, int>> ps;
            ps.push_back({x1, y1});
            ps.push_back({x1, y2});
            ps.push_back({x2, y1});
            ps.push_back({x2, y2});
            for(auto p : ps){
                if(points.count(p) == 1){
                    points.erase(p);
                }
                else{
                    points.emplace(p);
                }
            }
        }
        int perfect_area = (X2 - X1) * (Y2 - Y1);

        if(perfect_area != area){
            // cout << "area mismatch\n";
            return false;
        }

        if(points.size() != 4){
            // cout << "vertex num mismatch " << points.size() << endl;
            return false;
        }
        pair<int, int> point = {X1, Y1};
        if(points.count(point) == 0) return false;
        point = {X1, Y2};
        if(points.count(point) == 0) return false;
        point = {X2, Y1};
        if(points.count(point) == 0) return false;
        point = {X2, Y2};
        if(points.count(point) == 0) return false;

        // cout << "Perfect Rect\n";
        return true;
    }
};
// @lc code=end

int main(int argc, char** argv){
    Solution solu;
    vector<vector<int>> rects;
    cout << "Example 1" << endl;
    rects.push_back({1,1,3,3});
    rects.push_back({3,1,4,2});
    rects.push_back({3,2,4,4});
    rects.push_back({1,3,2,4});
    rects.push_back({2,3,3,4});
    solu.isRectangleCover(rects);
    return 0;
}