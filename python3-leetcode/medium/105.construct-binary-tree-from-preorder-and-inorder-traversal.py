#
# @lc app=leetcode id=105 lang=python3
#
# [105] Construct Binary Tree from Preorder and Inorder Traversal
#
# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
#
# algorithms
# Medium (64.34%)
# Likes:    14923
# Dislikes: 504
# Total Accepted:    1.3M
# Total Submissions: 2M
# Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
#
# Given two integer arrays preorder and inorder where preorder is the preorder
# traversal of a binary tree and inorder is the inorder traversal of the same
# tree, construct and return the binary tree.
# 
# 
# Example 1:
# 
# 
# Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
# Output: [3,9,20,null,null,15,7]
# 
# 
# Example 2:
# 
# 
# Input: preorder = [-1], inorder = [-1]
# Output: [-1]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= preorder.length <= 3000
# inorder.length == preorder.length
# -3000 <= preorder[i], inorder[i] <= 3000
# preorder and inorder consist of unique values.
# Each value of inorder also appears in preorder.
# preorder is guaranteed to be the preorder traversal of the tree.
# inorder is guaranteed to be the inorder traversal of the tree.
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTreeRecursive(self,preorder,inorder,index_dict,startIndex,endIndex):
       
        if( endIndex<startIndex):
            return None
        root_val = preorder.pop(0)  # Take the first element of preorder as the root
        root = TreeNode(root_val)
        mid = index_dict[root_val]
   
        root.left=self.buildTreeRecursive(preorder,inorder,index_dict,startIndex,mid-1)
        root.right=self.buildTreeRecursive(preorder,inorder,index_dict,mid+1,endIndex)
        return root 

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        index_dict = {value: index for index, value in enumerate(inorder)}#!O(n) space and O(n time )
       
        n=len(inorder)
        root =self.buildTreeRecursive(preorder,inorder,index_dict,0,n-1)
        return root 
       

        


        
# @lc code=end

