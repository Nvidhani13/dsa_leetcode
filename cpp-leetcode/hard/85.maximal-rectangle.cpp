/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (50.40%)
 * Likes:    10451
 * Dislikes: 185
 * Total Accepted:    490.4K
 * Total Submissions: 967.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a rows x cols binary matrix filled with 0's and 1's, find the largest
 * rectangle containing only 1's and return its area.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 6
 * Explanation: The maximal rectangle is shown in the above picture.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [["0"]]
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [["1"]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * rows == matrix.length
 * cols == matrix[i].length
 * 1 <= row, cols <= 200
 * matrix[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maximumHistogram(vector<int> &heights)
    {
        //! given the height we need to calculate mamimum

        int n = heights.size();
        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, n);
        stack<int> s;

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
            s.pop() ;
            
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
    
    
    
    
    int maximalRectangle(vector<vector<char>> &matrix)
    {
     int n =matrix.size();
     int m =matrix[0].size();
     vector<int>heights(m,0);

   int answer=0;
     for(int i =0;i<n;i++){
      for(int j=0;j<m;j++){
       if(matrix[i][j]=='1')
        heights[j]++;
        else{
            heights[j]=0;
        }
      }
      answer=max(answer,maximumHistogram(heights));
     }
     return answer;

    }
};
// @lc code=end
