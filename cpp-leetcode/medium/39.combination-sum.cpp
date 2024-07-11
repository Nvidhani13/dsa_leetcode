/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (70.88%)
 * Likes:    18271
 * Dislikes: 389
 * Total Accepted:    1.8M
 * Total Submissions: 2.5M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 *
 * The test cases are generated such that the number of unique combinations
 * that sum up to target is less than 150 combinations for the given input.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 *
 *
 * Example 3:
 *
 *
 * Input: candidates = [2], target = 1
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * All elements of candidates are distinct.
 * 1 <= target <= 40
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> answer;
    void Helper(vector<int> &candidates, int index, int target, vector<int> dummy)
    {
        if (target == 0)
        {
            answer.push_back(dummy);
            dummy.pop_back();
            return;
        }
        if (target < -1 || candidates.size() == index)
        {
            dummy.pop_back();
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            dummy.push_back(candidates[i]);
            Helper(candidates, i, target - candidates[i], dummy);
            dummy.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> dummy;
        Helper(candidates, 0, target, dummy);

        return answer;
    }
};
// @lc code=end
