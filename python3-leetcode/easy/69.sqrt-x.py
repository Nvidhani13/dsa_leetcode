#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#
# https://leetcode.com/problems/sqrtx/description/
#
# algorithms
# Easy (39.01%)
# Likes:    8142
# Dislikes: 4499
# Total Accepted:    2M
# Total Submissions: 5.2M
# Testcase Example:  '4'
#
# Given a non-negative integer x, return the square root of x rounded down to
# the nearest integer. The returned integer should be non-negative as well.
# 
# You must not use any built-in exponent function or operator.
# 
# 
# For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
# 
# 
# 
# Example 1:
# 
# 
# Input: x = 4
# Output: 2
# Explanation: The square root of 4 is 2, so we return 2.
# 
# 
# Example 2:
# 
# 
# Input: x = 8
# Output: 2
# Explanation: The square root of 8 is 2.82842..., and since we round it down
# to the nearest integer, 2 is returned.
# 
# 
# 
# Constraints:
# 
# 
# 0 <= x <= 2^31 - 1
# 
# 
#

# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        low=1
        high=x
        if(x==0):
            return x 
        while(low<=high):
            mid=(low+high)//2
            print(mid)

            if(mid*mid==x):
                return mid
            
            elif (mid*mid>x):
                high=mid-1
            else:
             low=mid+1
            print(low)
            print(high)
        return high
    

        

        
# @lc code=end

