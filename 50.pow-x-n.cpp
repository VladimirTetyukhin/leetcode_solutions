/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:

    double myPow(double x, long long n) {
        if(!n) return 1.0;
        if(n < 0) return 1.0 / myPow(x, -n);
        double x_pow_half_n = myPow(x, n / 2);
        if(n % 2) return x * x_pow_half_n * x_pow_half_n;
        return x_pow_half_n * x_pow_half_n;
    }
};
// @lc code=end

