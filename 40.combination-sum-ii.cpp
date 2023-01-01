/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    void combinationSumResursion(vector<int>& group, vector<int>& candidates_count, vector<vector<int>>& combinations, int sum, int target, int edge){
        if(sum > target) return;
        if(sum == target) {

            vector<int> group_without_zeroes;
            
            for(int i = 0; i < group.size(); ++i){
                for(int j = 0; j < group[i]; ++j){
                    group_without_zeroes.push_back(i);
                }
            }
            combinations.push_back(group_without_zeroes);
            return;
        }
        for(int i = edge; i < candidates_count.size(); ++i){
            if(!candidates_count[i]) continue;
            ++group[i];
            --candidates_count[i];

            combinationSumResursion(group, candidates_count, combinations, sum + i, target, i);

            ++candidates_count[i];
            --group[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> group(50, 0);
        vector<int> candidates_count(50, 0);
        vector<vector<int>>combinations;

        for(int i = 0; i < candidates.size(); ++i){
            ++candidates_count[candidates[i]];
        }
        combinationSumResursion(group, candidates_count, combinations, 0, target, 0);
        return combinations;
    }
};
// @lc code=end

