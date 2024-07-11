/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.30%)
 * Likes:    16611
 * Dislikes: 264
 * Total Accepted:    1.8M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void helperFunction(vector<int>& nums, int i, vector<int>& dummy, vector<vector<int>>& answer) {
        if (i == nums.size()) {
            answer.push_back(dummy);
            return;
        }
        // Include the current element
        dummy.push_back(nums[i]);
        helperFunction(nums, i + 1, dummy, answer);
        dummy.pop_back(); // Backtrack to exclude the current element
        
        // Exclude the current element
        helperFunction(nums, i + 1, dummy, answer);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> dummy;
        helperFunction(nums, 0, dummy, answer);
        return answer;
    }
};
// @lc code=end

