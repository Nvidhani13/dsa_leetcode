/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (46.55%)
 * Likes:    10029
 * Dislikes: 223
 * Total Accepted:    687.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given an m x n binary matrix filled with 0's and 1's, find the largest
 * square containing only 1's and return its area.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [["0"]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n =matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSide=0;
        for(int i =0;i<n;i++){
            if(matrix[i][0]=='1')
              dp[i][0]=1;
        }
        for(int i =0;i<m;i++){
            if(matrix[i][0]=='1')
              dp[0][i]=1;
        }
        for(int i =1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1')
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                else{
                    dp[i][j]=0;
                }
                maxSide=max(maxSide,dp[i][j]);
            }
        }
        return maxSide*maxSide;
        
    }
};
// @lc code=end

