/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double Helper(vector<int>& nums1, vector<int>& nums2, int total, int low, int high) {
        
        int mid1 = (low + high) / 2; 
        int mid2 = total - mid1;
       

        int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
        int right1 = (mid1 < nums1.size()) ? nums1[mid1] : INT_MAX;

        int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
        int right2 = (mid2 < nums2.size()) ? nums2[mid2] : INT_MAX;
        

        if (left1 <= right2 && left2 <= right1) {
   
            if ((nums1.size() + nums2.size()) % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else {
                return min(right1, right2);
            }
        }
        if (left1 > right2) {
            return Helper(nums1, nums2, total, low, mid1 - 1);
        } else {
            return Helper(nums1, nums2, total, mid1 + 1, high);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int total = (nums1.size() + nums2.size() ) / 2;
        return Helper(nums1, nums2, total, 0, nums1.size());
    }
};
// @lc code=end

