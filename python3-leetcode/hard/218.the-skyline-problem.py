#
# @lc app=leetcode id=218 lang=python3
#
# [218] The Skyline Problem
#
# https://leetcode.com/problems/the-skyline-problem/description/
#
# algorithms
# Hard (42.63%)
# Likes:    5826
# Dislikes: 259
# Total Accepted:    285.7K
# Total Submissions: 670.1K
# Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
#
# A city's skyline is the outer contour of the silhouette formed by all the
# buildings in that city when viewed from a distance. Given the locations and
# heights of all the buildings, return the skyline formed by these buildings
# collectively.
# 
# The geometric information of each building is given in the array buildings
# where buildings[i] = [lefti, righti, heighti]:
# 
# 
# lefti is the x coordinate of the left edge of the i^th building.
# righti is the x coordinate of the right edge of the i^th building.
# heighti is the height of the i^th building.
# 
# 
# You may assume all buildings are perfect rectangles grounded on an absolutely
# flat surface at height 0.
# 
# The skyline should be represented as a list of "key points" sorted by their
# x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left
# endpoint of some horizontal segment in the skyline except the last point in
# the list, which always has a y-coordinate 0 and is used to mark the skyline's
# termination where the rightmost building ends. Any ground between the
# leftmost and rightmost buildings should be part of the skyline's contour.
# 
# Note: There must be no consecutive horizontal lines of equal height in the
# output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is
# not acceptable; the three lines of height 5 should be merged into one in the
# final output as such: [...,[2 3],[4 5],[12 7],...]
# 
# 
# Example 1:
# 
# 
# Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
# Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
# Explanation:
# Figure A shows the buildings of the input.
# Figure B shows the skyline formed by those buildings. The red points in
# figure B represent the key points in the output list.
# 
# 
# Example 2:
# 
# 
# Input: buildings = [[0,2,3],[2,5,3]]
# Output: [[0,3],[5,0]]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= buildings.length <= 10^4
# 0 <= lefti < righti <= 2^31 - 1
# 1 <= heighti <= 2^31 - 1
# buildings is sorted by lefti in non-decreasing order.
# 
# 
#

# @lc code=start
class Solution:
     #first thing first will iterate from each building if current building is left of highest building so bar we have to pop 
        #and find that x value on top then we will also pop all value whose right is small then the current max x then finally we will do current_x,
        #top of queueu height and push it in results 
        # curr_h =0 if pq other wise pq[0][0] in the current loop the loop that is checking the left of current of top from the current building 
        # if first condition is not checked then current building height has to be checked with top of queue if is bggier we have to continously push in reults 
        #and update the cuur_h 
        #
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        results=[]
        pq=[]
        curr_h=0
        i=0
        while i<len(buildings) :
            while pq and pq[0][2]<buildings[i][0]:
                current_height_max_x=heapq.heappop(pq)[2]
                while pq and pq[0][2]<=current_height_max_x:
                    heapq.heappop(pq)
                curr_h=0 if not pq else pq[0][0]*-1
                results.append([current_height_max_x, curr_h])
        

            if curr_h<buildings[i][2]:
                curr_h=buildings[i][2]
             
                while i <len(buildings)-1 and buildings[i][0]==buildings[i+1][0]:
                    curr_h=max(curr_h,buildings[i+1][2])
                    heapq.heappush(pq,(-buildings[i][2],-buildings[i][0],buildings[i][1]))
                    i+=1
                results.append((buildings[i][0],curr_h))
            
            heapq.heappush(pq,(-buildings[i][2],-buildings[i][0],buildings[i][1]))
            i+=1
        
        while pq:
            max_height_end_x = heapq.heappop(pq)[2]
            while pq and pq[0][2] <= max_height_end_x:
                heapq.heappop(pq)
            cur_h = 0 if not pq else -pq[0][0]
            results.append([max_height_end_x, cur_h])
        return results 
   
    


                


        
# @lc code=end

