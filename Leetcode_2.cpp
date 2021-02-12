/*
* 2. 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

提示：
    每个链表中的节点数在范围 [1, 100] 内
    0 <= Node.val <= 9
    题目数据保证列表表示的数字不含前导零

* 
* 解题思路： 
*   同时遍历两个链表，如果该节点为空，就用 0 代替，两数相加；sum%10是当前位的值，sum/10是进位值
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//243 + 560 = sum1
//243 + 56 = sum2
//如果两链表不等
//sum1-243
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* root = new ListNode(0);
        ListNode* p = root;
        int d = 0;
        while(l1 || l2)
        {
            int sum = 0;           
            int x = l1 ? l1->val : 0;
			int y = l2 ? l2->val : 0;
			sum = x + y + d;         
           
            p->next = new ListNode(sum%10);
            p = p->next;
            d = sum/10;  
            if(l1)
                l1 = l1->next;            
            if(l2)
                l2 = l2->next;
        }
        
        if(d > 0)
            p->next = new ListNode(d);
        return root->next;
    }
};