#
# @lc app=leetcode id=25 lang=python3
#
# [25] Reverse Nodes in k-Group
#
# https://leetcode.com/problems/reverse-nodes-in-k-group/description/
#
# algorithms
# Hard (58.66%)
# Likes:    13608
# Dislikes: 692
# Total Accepted:    959.4K
# Total Submissions: 1.6M
# Testcase Example:  '[1,2,3,4,5]\n2'
#
# Given the head of a linked list, reverse the nodes of the list k at a time,
# and return the modified list.
# 
# k is a positive integer and is less than or equal to the length of the linked
# list. If the number of nodes is not a multiple of k then left-out nodes, in
# the end, should remain as it is.
# 
# You may not alter the values in the list's nodes, only nodes themselves may
# be changed.
# 
# 
# Example 1:
# 
# 
# Input: head = [1,2,3,4,5], k = 2
# Output: [2,1,4,3,5]
# 
# 
# Example 2:
# 
# 
# Input: head = [1,2,3,4,5], k = 3
# Output: [3,2,1,4,5]
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the list is n.
# 1 <= k <= n <= 5000
# 0 <= Node.val <= 1000
# 
# 
# 
# Follow-up: Can you solve the problem in O(1) extra memory space?
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def findKNode(self, head: ListNode, k: int) -> ListNode:
        count = 0
        while head and count < k:
            head = head.next
            count += 1
        return head if count == k else None
    
    # def reverse(self, head: ListNode) -> ListNode:
    #     prev = None
    #     current = head
    #     while current:
    #         next_node = current.next
    #         current.next = prev
    #         prev = current
    #         current = next_node
    #     return prev

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        group_prev=dummy
        while True:
            #!lets think abouth base condition later 

            kth =self.findKNode(group_prev,k)

        
            if(not kth):
                break#!this the base condition 
            group_next=kth.next
            curr,prev=group_prev.next,group_next#! basically we are 
            #! gonna treat group_next as Null until we can 
            while curr!=group_next:
                next=curr.next
                curr.next=prev
                prev=curr
                curr=next
                
            if(group_prev.next==head):
                head=kth
                
            temp=group_prev

            group_prev=group_prev.next
            temp.next=kth
           

            


        return head
        


        
# @lc code=end

