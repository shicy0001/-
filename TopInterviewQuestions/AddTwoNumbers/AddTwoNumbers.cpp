/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
作者：shicy
日期：2019-12-06

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *p1 = l1, *p2 = l2, *res = NULL, *last = NULL;
        int x = 0, y = 0, sum = 0, carry = 0;

        while(p1 != NULL || p2 != NULL)
        {   
            x = 0;y = 0;
            if (p1 != NULL)
                x = p1->val;
            if (p2 != NULL)
                y = p2->val;

            sum = x + y + carry;
            
            carry = sum/10;
            
            ListNode *p = new ListNode(sum%10);

            if(res == NULL)
                res = p;
            else
                last->next = p;
            
            last = p;
            if(p1 != NULL)
                p1 = p1->next;
            if(p2 != NULL)
                p2 = p2->next;
        }

        if (carry > 0)
        {
            ListNode *p = new ListNode(1);
            last->next = p;
        }
        return res;
        
    }
};