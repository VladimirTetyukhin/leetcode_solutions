/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged_intervals;
        sort(intervals.begin(), intervals.end());

        int left_border = intervals[0][0];
        int right_border = intervals[0][1];

        for(int i = 0; i < intervals.size(); ++i){
            if(right_border < intervals[i][0]){
                merged_intervals.push_back({left_border, right_border});
                left_border = intervals[i][0];
                right_border = intervals[i][1];
            } else{
                if(intervals[i][1] > right_border){
                    right_border = intervals[i][1];
                }
            }
        }
        merged_intervals.push_back({left_border, right_border});
        return merged_intervals;
    }
};
// @lc code=end

