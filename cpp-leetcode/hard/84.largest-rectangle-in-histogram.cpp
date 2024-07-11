/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (44.45%)
 * Likes:    17027
 * Dislikes: 275
 * Total Accepted:    902.9K
 * Total Submissions: 2M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 * in the histogram.
 *
 *
 * Example 1:
 *
 *
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10
 * units.
 *
 *
 * Example 2:
 *
 *
 * Input: heights = [2,4]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        int n = heights.size();
        vector<int> prevSmaller(n, -1); 

        vector<int> nextSmaller(n, n);

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            if (!s.empty())
                prevSmaller[i] = s.top();

            s.push(i);
        }
        while (!s.empty())
        {
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            if (!s.empty())
                nextSmaller[i] = s.top();

            s.push(i);
        }
         int answer=0;
    for(int i =0;i<n;i++){
        answer=max(answer,(nextSmaller[i]-prevSmaller[i]-1)*heights[i]);
    }
    return answer;
    }
   
};
// @lc code=end
