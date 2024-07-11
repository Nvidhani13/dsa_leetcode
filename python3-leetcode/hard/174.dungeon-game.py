#
# @lc app=leetcode id=174 lang=python3
#
# [174] Dungeon Game
#
# https://leetcode.com/problems/dungeon-game/description/
#
# algorithms
# Hard (38.26%)
# Likes:    5789
# Dislikes: 107
# Total Accepted:    228.8K
# Total Submissions: 597.9K
# Testcase Example:  '[[-2,-3,3],[-5,-10,1],[10,30,-5]]'
#
# The demons had captured the princess and imprisoned her in the bottom-right
# corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D
# grid. Our valiant knight was initially positioned in the top-left room and
# must fight his way through dungeon to rescue the princess.
# 
# The knight has an initial health point represented by a positive integer. If
# at any point his health point drops to 0 or below, he dies immediately.
# 
# Some of the rooms are guarded by demons (represented by negative integers),
# so the knight loses health upon entering these rooms; other rooms are either
# empty (represented as 0) or contain magic orbs that increase the knight's
# health (represented by positive integers).
# 
# To reach the princess as quickly as possible, the knight decides to move only
# rightward or downward in each step.
# 
# Return the knight's minimum initial health so that he can rescue the
# princess.
# 
# Note that any room can contain threats or power-ups, even the first room the
# knight enters and the bottom-right room where the princess is imprisoned.
# 
# 
# Example 1:
# 
# 
# Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
# Output: 7
# Explanation: The initial health of the knight must be at least 7 if he
# follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
# 
# 
# Example 2:
# 
# 
# Input: dungeon = [[0]]
# Output: 1
# 
# 
# 
# Constraints:
# 
# 
# m == dungeon.length
# n == dungeon[i].length
# 1 <= m, n <= 200
# -1000 <= dungeon[i][j] <= 1000
# 
# 
#

# @lc code=start
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m=len(dungeon)
        n =len(dungeon[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        if (dungeon[m-1][n-1] < 0):
            dp[m-1][n-1]=dungeon[m-1][n-1]
            
        else:
            dp[m-1][n-1]=0
            
        for i in range(m-2,-1,-1):
            dp[i][n-1]= dungeon[i][n-1]+dp[i+1][n-1] if(dungeon[i][n-1]+dp[i+1][n-1]<0) else 0
           
        for i in range(n-2,-1,-1):
            dp[m-1][i]=dungeon[m-1][i]+dp[m-1][i+1] if(dungeon[m-1][i]+dp[m-1][i+1]<0) else 0
           
        
        for i in range(m-2,-1,-1):
            for j in range (n-2,-1,-1):
                dp[i][j]= dungeon[i][j]+max(dp[i+1][j],dp[i][j+1])if( dungeon[i][j]+max(dp[i+1][j],dp[i][j+1])<0) else 0
                
        return dp[0][0]*-1+1 if dp[0][0]<0 else 1



        
# @lc code=end

