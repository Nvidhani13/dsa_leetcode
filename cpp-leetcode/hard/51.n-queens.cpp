/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (67.92%)
 * Likes:    12057
 * Dislikes: 275
 * Total Accepted:    700.7K
 * Total Submissions: 1M
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [["Q"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> answer;

   bool isSafe(vector<string> & dummy,int row,int col,int n ){
      //checking for left hand side 
      int i ,j;
      for (i =0;i<col;i++){
        if(dummy[row][i]=='Q')
          return false ;
        
      }
      for (i =row,j=col;i>=0&&j>=0;i--,j--){
        if(dummy[i][j]=='Q')
          return false;
      }
      for (i =row,j=col;i>=0&&j<n;i--,j++){
        if(dummy[i][j]=='Q')
          return false;
      }
      return true ;

   }
    void Helper(vector<string>& dummy,int col,int n ){
        if(col==n){
            //base condition 1 
            answer.push_back(dummy);
            return ;
        }
        for (int i =0;i<n;i++){
            if(isSafe(dummy,i,col,n)){
                dummy[i][col]='Q';
                Helper(dummy,col+1,n);
                dummy[i][col]='.';//working kind of popup 


            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> dummy(n, string(n, '.')); 
        Helper(dummy,0,n);
       return answer;
    }
};
// @lc code=end

