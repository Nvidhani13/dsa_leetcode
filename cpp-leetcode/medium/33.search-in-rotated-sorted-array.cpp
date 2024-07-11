/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (40.63%)
 * Likes:    25678
 * Dislikes: 1536
 * Total Accepted:    2.7M
 * Total Submissions: 6.5M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 * 
 * Prior to being passed to your function, nums is possibly rotated at an
 * unknown pivot index k (1 <= k < nums.length) such that the resulting array
 * is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
 * and become [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is an ascending array that is possibly rotated.
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int target,int low,int high){
        if(low>high)
         return -1;
         if(low==high)
          return nums[low] == target ? low : -1;
          int mid=(low+high)/2;
          if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
             return binarySearch(nums,target,low,mid-1);
             else{
             return binarySearch(nums,target,mid+1,high);

             }
             return -1;
    }
    int search(vector<int>& nums, int target) {
        int left =0;
        int right=nums.size()-1;
        int pivot  =0 ;
        while(right>=left){
            pivot =(left+right)/2;
            if(nums[pivot]==target){
                return pivot;
            }
            if( left==right){
                
                break;
            }
            if (nums[pivot]>nums[pivot+1]){
                break;
            }
            else if(nums[left]>nums[pivot]){
                right=pivot-1;
            }
            else{
                left=pivot+1;
            }
        }


        left =0;
        right=nums.size()-1;
        if(nums[pivot]==target){
            return pivot;
        }
        if(nums[0]<=target)
        pivot=binarySearch(nums,target,0,pivot-1);
        else{
            pivot=binarySearch(nums,target,pivot+1,nums.size()-1);
        }

        
      return pivot;
    }
};
// @lc code=end

