#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(!matrix[i][j]) continue;
                max = 1;
                for(int k = i; k < matrix[0].size(); ++j){
            }
        }
    }
};
// @lc code=end

