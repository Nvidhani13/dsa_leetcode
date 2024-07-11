/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (39.38%)
 * Likes:    16557
 * Dislikes: 1825
 * Total Accepted:    1.2M
 * Total Submissions: 3M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array nums. Return the smallest positive integer
 * that is not present in nums.
 * 
 * You must implement an algorithm that runs in O(n) time and uses O(1)
 * auxiliary space.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,0]
 * Output: 3
 * Explanation: The numbers in the range [1,2] are all in the array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Explanation: 1 is in the array but 2 is missing.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 * Explanation: The smallest positive integer 1 is missing.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        
        // Step 1: Replace negative numbers and numbers larger than the array size with a placeholder
        for (int i = 0; i < length; ++i) {
            if (nums[i] <= 0 || nums[i] > length) {
                nums[i] = length + 1;
            }
        }

        // Step 2: Use the index as a hash key and mark the presence of an element
        for (int i = 0; i < length; ++i) {
            int num = abs(nums[i]);
            if (num <= length) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // Step 3: Find the first index which has a positive value
        for (int i = 0; i < length; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        // If all indices are marked, the missing number is length + 1
        return length + 1;
    }
};

// @lc code=end

