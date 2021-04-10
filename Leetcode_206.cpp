/*
* 206. 反转链表
*
反转一个单链表。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

* 
* 解题思路： 
*   
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(head)
        {
            next = head->next;
            
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};