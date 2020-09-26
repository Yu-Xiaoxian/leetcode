/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
#include <limits.h>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        if(S.empty()){
            return result;
        }
        vector<int> pos(26,0);
        for(int i = 0; i<S.size(); i++){
            pos[S[i]-'a'] = i;
        }
        for (int i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
            idx = max(idx, pos[S[i] - 'a']);
            if (idx == i) result.push_back(i - exchange(last_i, i + 1) + 1);
        }
        return result;
    }
};
// @lc code=end

int main(){
    Solution solut;
    string input = "ababcbacadefegdehijhklij";
    vector<int> result = solut.partitionLabels(input);
    for(auto n : result){
        std::cout << n << ",";
    }
    std::cout << std::endl;
    return 0;
}

