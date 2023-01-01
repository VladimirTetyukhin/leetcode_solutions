/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:

    bool canJump(vector<int>& nums) {
        int max_jump = 0, i = 0;
        while(true){
            max_jump = max(max_jump--, nums[i] + i);
            if(max_jump >= nums.size() - 1) return 1;
            if(max_jump == i++) return 0;
        }
    }
};
// @lc code=end
