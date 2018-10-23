/*
ɾ���������ظ��Ľ�� https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����137194
����֪ʶ�㣺 ����

����˼·��
    ��¼ǰһ���ڵ�

    ע�⣺��Ϊͷ���Ҳ�����ظ���ɾ����������Ҫ����һ���µĽ�㣬ָ��ԭͷ���

    ��Ϊֻ�� OJ�����Դ���ʽΪ�����ڵ㣬��û��ɾ�������Ҫע��

�ύ��¼��
    1. ͷ�ڵ㴦�����
    2. û�б��ֺ� pre �� cur �����ڹ�ϵ

*/
#pragma once
#include "../all.h"

class Solution {
public:
    ListNode * deleteDuplication(ListNode* pHead)
    {   
        if (pHead == NULL) return pHead;

        ListNode* head = new ListNode{-1};  // ����һ��ͷ���
        head->next = pHead;

        ListNode* pre = head;
        ListNode* cur = pHead;
        while (cur != NULL && cur->next != NULL) {
            if (cur->val != cur->next->val) {
                pre = cur;
                cur = cur->next;
            }
            else {
                int val = cur->val;
                while (cur != NULL && cur->val == val)
                    cur = cur->next;
                pre->next = cur;
            }
        }

        return head->next;
    }
};

void solve()
{
    
}
