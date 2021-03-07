/*
* 83. 删除排序链表中的重复元素
*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3

* 
* 解题思路： 
*   链表删除，只需要移动前后指针就可以
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* p = head->next;
        ListNode* pre = head;
        while(p)
        {
            if(pre->val == p->val)
                pre->next = p->next;                
            else
                pre = p;                
            p = p->next;
        }       
        return head;
    }
};