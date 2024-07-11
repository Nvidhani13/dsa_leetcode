/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (43.90%)
 * Likes:    20110
 * Dislikes: 496
 * Total Accepted:    2M
 * Total Submissions: 4.5M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int first(vector<int>& nums, int target, int left, int right) {
        if (right >= left) {
            int mid = left + (right - left) / 2;
            if ((mid == 0 || target > nums[mid - 1]) && target == nums[mid])
                return mid;
            else if (target > nums[mid])
                return first(nums, target, mid + 1, right);
            else
                return first(nums, target, left, mid - 1);
        }
        return -1;
    }

    int last(vector<int>& nums, int target, int left, int right) {
        if (right >= left) {
            int mid = left + (right - left) / 2;
            if (mid == nums.size() - 1 || (target < nums[mid + 1]) && target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                return last(nums, target, left, mid - 1);
            } else {
                return last(nums, target, mid + 1, right);
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int firstOccurrence = first(nums, target, 0, right);
        int lastOccurrence = last(nums, target, 0, right);
        if (firstOccurrence == -1 || lastOccurrence == -1)
            return {-1, -1};
        else
            return {firstOccurrence, lastOccurrence};
    }
};
// @lc code=end

