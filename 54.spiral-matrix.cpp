/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix[0].size();
        int m = matrix.size();
        int i = 0, j = 0;

        int upper_border = 0;
        int right_border = n;
        int lower_border = m;
        int left_border = -1;

        int orientation = 0;

        for(int k = 0; k < n * m; ++k){
            res.push_back(matrix[i][j]);
            
            if(orientation == 0){
                if(j + 1 == right_border){
                    orientation = 1;
                    --right_border;
                    ++i;
                } else {
                    ++j;
                }
            } else if(orientation == 1){
                if(i + 1 == lower_border){
                    orientation = 2;
                    --lower_border;
                    --j;
                } else {
                    ++i;
                }
            } else if(orientation == 2){
                if(j - 1 == left_border){
                    orientation = 3;
                    ++left_border;
                    --i;
                } else {
                    --j;
                }
            } else {
                if(i - 1 == upper_border){
                    orientation = 0;
                    ++upper_border;
                    ++j;
                } else {
                    --i;
                }
            }
        }

        return res;
        
    }
};
// @lc code=end

