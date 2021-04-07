/*
* 203. 移除链表元素
*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

提示：
	列表中的节点在范围 [0, 104] 内
    1 <= Node.val <= 50
    0 <= k <= 50
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* r = new ListNode(0);
        r->next = head;
        ListNode* p = head;
        ListNode* pre = r;
        while(p)
        {
            if(val == p->val)
            {
                pre->next = p->next;
                delete p;
            }
            else
                pre = p;
            p = pre->next;
        }
        return r->next;
    }
};