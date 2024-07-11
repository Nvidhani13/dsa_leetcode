/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (73.70%)
 * Likes:    3780
 * Dislikes: 259
 * Total Accepted:    376K
 * Total Submissions: 510K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
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

    bool isSafe(vector<string>& dummy, int row, int col, int n) {
        // Check for queens on the left-hand side
        for (int i = 0; i < col; i++) {
            if (dummy[row][i] == 'Q')
                return false;
        }
        
        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (dummy[i][j] == 'Q')
                return false;
        }
        
        // Check lower diagonal on left side
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (dummy[i][j] == 'Q')
                return false;
        }
        
        return true;
    }

    void Helper(vector<string>& dummy, int col, int n) {
        if (col == n) {
            // Base condition
            answer.push_back(dummy);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(dummy, i, col, n)) {
                dummy[i][col] = 'Q';
                Helper(dummy, col + 1, n);
                dummy[i][col] = '.'; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> dummy(n, string(n, '.')); 
        Helper(dummy, 0, n);
        return answer.size();
    }
};

// @lc code=end

