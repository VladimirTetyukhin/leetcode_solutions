/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    void combinationSumResursion(vector<int>& group, vector<int>& candidates, vector<vector <int>>& combinations, int sum, int target, int elem){
        if(sum > target) return;
        if(sum == target) {
            combinations.push_back(group);
            return;
        }
        for(int i = elem; i < candidates.size(); ++i){
            group.push_back(candidates[i]);
            combinationSumResursion(group, candidates, combinations, sum + candidates[i], target, i);
            group.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> group;
        vector<vector <int>> combinations;
        combinationSumResursion(group, candidates, combinations, 0, target, 0);
        return combinations;
    }
};
// @lc code=end

