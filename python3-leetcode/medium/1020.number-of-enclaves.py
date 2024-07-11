#
# @lc app=leetcode id=1020 lang=python3
#
# [1020] Number of Enclaves
#
# https://leetcode.com/problems/number-of-enclaves/description/
#
# algorithms
# Medium (68.73%)
# Likes:    3918
# Dislikes: 75
# Total Accepted:    211.8K
# Total Submissions: 308.2K
# Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
#
# You are given an m x n binary matrix grid, where 0 represents a sea cell and
# 1 represents a land cell.
# 
# A move consists of walking from one land cell to another adjacent
# (4-directionally) land cell or walking off the boundary of the grid.
# 
# Return the number of land cells in grid for which we cannot walk off the
# boundary of the grid in any number of moves.
# 
# 
# Example 1:
# 
# 
# Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
# Output: 3
# Explanation: There are three 1s that are enclosed by 0s, and one 1 that is
# not enclosed because its on the boundary.
# 
# 
# Example 2:
# 
# 
# Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
# Output: 0
# Explanation: All 1s are either on the boundary or can reach the boundary.
# 
# 
# 
# Constraints:
# 
# 
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 500
# grid[i][j] is either 0 or 1.
# 
# 
#

# @lc code=start
class Solution:
    


    def dfs(self,grid,i,j):
        directions=[(-1,0),(1,0),(0,-1),(0,1)]
        m=len(grid)
        n=len(grid[0])
        grid[i][j]=0
        for direction in directions:
            dx,dy=i+direction[0],j+direction[1]     
            if 0 <= dx < m and 0 <= dy < n and grid[dx][dy] == 1:
                self.dfs(grid, dx, dy)

        
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])


        for i in range (m):
            if(grid[i][0]==1):
                self.dfs(grid,i,0)
            if(grid[i][n-1]==1):
                self.dfs(grid,i,n-1)
        
        for i in range(n):
            if(grid[0][i]==1):
                self.dfs(grid,0,i)
            if(grid[m-1][i]==1):
                self.dfs(grid,m-1,i)
        answer=0
        for i in range(m):
            for j in range(n):
                answer+=grid[i][j]
        return answer



        






        
# @lc code=end

