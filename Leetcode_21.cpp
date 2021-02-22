/*
* 21. 合并两个有序链表
*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

提示：
两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列

* 
* 解题思路： 
*   双指针迭代
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* root = new ListNode(-101);
        ListNode* newp = root;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				newp->next = l1;
				l1 = l1->next;
			}
			else
			{
				newp->next = l2;
				l2 = l2->next;
			}
            newp = newp->next;
		}
		newp->next = l1 == NULL?l2:l1;
		return root->next;
	}
};