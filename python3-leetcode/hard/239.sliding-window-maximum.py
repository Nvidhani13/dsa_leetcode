#
# @lc app=leetcode id=239 lang=python3
#
# [239] Sliding Window Maximum
#
# https://leetcode.com/problems/sliding-window-maximum/description/
#
# algorithms
# Hard (46.57%)
# Likes:    18057
# Dislikes: 670
# Total Accepted:    1M
# Total Submissions: 2.2M
# Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
#
# You are given an array of integers nums, there is a sliding window of size k
# which is moving from the very left of the array to the very right. You can
# only see the k numbers in the window. Each time the sliding window moves
# right by one position.
# 
# Return the max sliding window.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
# Output: [3,3,5,5,6,7]
# Explanation: 
# Window position                Max
# ---------------               -----
# [1  3  -1] -3  5  3  6  7       3
# ⁠1 [3  -1  -3] 5  3  6  7       3
# ⁠1  3 [-1  -3  5] 3  6  7       5
# ⁠1  3  -1 [-3  5  3] 6  7       5
# ⁠1  3  -1  -3 [5  3  6] 7       6
# ⁠1  3  -1  -3  5 [3  6  7]      7
# 
# 
# Example 2:
# 
# 
# Input: nums = [1], k = 1
# Output: [1]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^5
# -10^4 <= nums[i] <= 10^4
# 1 <= k <= nums.length
# 
# 
#

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # Edge cases
        if not nums:
            return []
        if k == 0:
            return nums
    
    # Initialize max-heap and result list
        max_heap = []
        result = []

    # Insert the first k elements into the max-heap
        for i in range(k):
            heapq.heappush(max_heap, (-nums[i], i))
    
    # Add the maximum for the first window
        result.append(-max_heap[0][0])
    
    # Slide the window
        for i in range(k, len(nums)):
        # Insert the current element into the heap
            heapq.heappush(max_heap, (-nums[i], i))
        
        # Remove elements not in the current window
            while max_heap[0][1] <= i - k:
                heapq.heappop(max_heap)
        
        # The root of the heap is the maximum for the current window
            result.append(-max_heap[0][0])
    
        return result
        
# @lc code=end

