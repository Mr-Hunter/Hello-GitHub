/*
��ת���� https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ��������ת�����������������Ԫ�ء�

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����236616
����֪ʶ�㣺 ����

����˼·��
    1. ��������϶���ָ����ƶ���
    2. ��������һ��ջ

�ύ��¼��
    1. ����ջ�ٴ�ʧ�ܣ��������Ըо�û�����ˣ�
    2. ָ���ƶ����˳�����������ѭ��
*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * ReverseList(ListNode* pHead) {
        // �ٴ�ʧ��
        /*stack<ListNode *> sl;
        ListNode* p = pHead;
        while (p) {
            sl.push(p);
            p = p->next;
        }

        ListNode * h = sl.top();
        sl.pop();
        p = h;
        while (!sl.empty()) {
            p->next = sl.top();
            p = p->next;
            sl.pop();
        }
        p->next = NULL;
        return h;*/

        // ��������
        if (pHead == NULL)
            return NULL;

        ListNode* cur = pHead;
        ListNode* pre = NULL;
        ListNode* nxt = cur->next;
        cur->next = NULL;
        while (nxt) {
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
            cur->next = pre;
        }
        return cur;
    }
};

void
solve()
{
    ListNode l1{ 1 };
    ListNode l2{ 2 };
    ListNode l3{ 3 };
    ListNode l4{ 4 };
    ListNode l5{ 5 };
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    ListNode* ret = Solution().ReverseList(&l1);

}