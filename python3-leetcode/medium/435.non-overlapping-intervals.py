#
# @lc app=leetcode id=435 lang=python3
#
# [435] Non-overlapping Intervals
#
# https://leetcode.com/problems/non-overlapping-intervals/description/
#
# algorithms
# Medium (53.59%)
# Likes:    8106
# Dislikes: 219
# Total Accepted:    591.9K
# Total Submissions: 1.1M
# Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
#
# Given an array of intervals intervals where intervals[i] = [starti, endi],
# return the minimum number of intervals you need to remove to make the rest of
# the intervals non-overlapping.
# 
# 
# Example 1:
# 
# 
# Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
# Output: 1
# Explanation: [1,3] can be removed and the rest of the intervals are
# non-overlapping.
# 
# 
# Example 2:
# 
# 
# Input: intervals = [[1,2],[1,2],[1,2]]
# Output: 2
# Explanation: You need to remove two [1,2] to make the rest of the intervals
# non-overlapping.
# 
# 
# Example 3:
# 
# 
# Input: intervals = [[1,2],[2,3]]
# Output: 0
# Explanation: You don't need to remove any of the intervals since they're
# already non-overlapping.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= intervals.length <= 10^5
# intervals[i].length == 2
# -5 * 10^4 <= starti < endi <= 5 * 10^4
# 
# 
#

# @lc code=start
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        count=0
        left=0
        n=len(intervals)
        right=n
        while(right<n):
            if(intervals[left][1]<=intervals[right][0]):
                left=right
                right=right+1
                #!no overlapping condition apart from this 
            elif(intervals[left][1]<intervals[right][1]):
                count=count+1
                right=right+1
            else:
                left=right
                right=right+1
                count+=1
        return count
        
# @lc code=end

