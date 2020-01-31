/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
作者:shicy
日期：2020-01-31

题目描述：

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

解法：可递归或迭代反转

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
    ListNode* reverseListRecursively(ListNode* head) {
        if(head->next == NULL || head == NULL)
            return head;

        else
        {
            ListNode *p = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;

            return p;
        }
    }

    ListNode* reverseListIteratively(ListNode* head) {
        ListNode *p = head, *tempLast = NULL, *tempNext = NULL;

        while(p != NULL)
        {   
            tempNext = p->next;
            p->next = tempLast;
            tempLast = p;
            p = tempNext;
        }
        return tempLast;
    }
};



