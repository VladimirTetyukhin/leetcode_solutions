/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(!intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }
        
        int i = 0, j = 0;
        for(i = 0; i < intervals.size(); ++i){
            if(intervals[i][0] >= newInterval[0]){
                break;
            }
        }
        --i;
        for(j = i; j < intervals.size(); ++j){
            if(intervals[j][1] > newInterval[1]){
                if(j)--j;
                break;
            }
        }
        if(i < intervals.size() && intervals[i][0] < newInterval[0]){
            newInterval[0] = intervals[i][0];
        }
        if(j < intervals.size() - 1 && intervals[j + 1][0] == newInterval[1]) ++j;

        if(j < intervals.size() && intervals[j][1] > newInterval[1]){
            newInterval[1] = intervals[j][1];
        }
        intervals.erase(intervals.begin() + i, intervals.begin() + j + 1);
        intervals.insert(intervals.begin() + i, newInterval);

        return intervals;
    }
};
// @lc code=end

