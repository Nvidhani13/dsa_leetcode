/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (17.41%)
 * Likes:    4985
 * Dislikes: 14706
 * Total Accepted:    723.7K
 * Total Submissions: 4.2M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, 8.345 would be truncated to 8, and -2.7335
 * would be truncated to -2.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * Note: Assume we are dealing with an environment that could only store
 * integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this
 * problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31
 * - 1, and if the quotient is strictly less than -2^31, then return -2^31.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = 3.33333.. which is truncated to 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positive
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b){  // while dividend is greater than or equal to divisor
            short q = 0;
            while(a > (b<<(q+1)))
                q++;
            ans += (1<<q);  // add the power of 2 found to the answer
            a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
        }
        if(ans == (1<<31) and isPositive)   // if ans cannot be stored in signed int
            return INT_MAX;
        return isPositive ? ans : -ans;
    }
};
// @lc code=end

