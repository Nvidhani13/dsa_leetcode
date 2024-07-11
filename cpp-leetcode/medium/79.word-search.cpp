/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (41.94%)
 * Likes:    15600
 * Dislikes: 651
 * Total Accepted:    1.6M
 * Total Submissions: 3.8M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * 
 * 
 * 
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 * 
 */

// @lc code=start
class Solution {
public:
    int Row;
    int Col;
    int wordSize;

    bool Helper(vector<vector<char>>& board, string& word, int i, int row, int col) {
        if (i == wordSize) 
            return true;
        if (row < 0 || Row <= row || col < 0 || Col <= col || board[row][col] != word[i])
            return false;

        char current = board[row][col];
        board[row][col] = '.';
        
        bool found = Helper(board, word, i + 1, row + 1, col) ||
                     Helper(board, word, i + 1, row - 1, col) ||
                     Helper(board, word, i + 1, row, col + 1) ||
                     Helper(board, word, i + 1, row, col - 1);

        board[row][col] = current;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        this->Row = board.size();
        this->Col = board[0].size();
        this->wordSize = word.size();
        
        for (int row = 0; row < Row; ++row) {
            for (int col = 0; col < Col; ++col) {
                if (Helper(board, word, 0, row, col)) 
                    return true;
            }
        }
        return false;
    }
};

// @lc code=end

