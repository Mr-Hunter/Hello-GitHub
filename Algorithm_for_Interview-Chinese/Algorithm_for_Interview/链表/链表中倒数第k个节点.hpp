/*
�����е�����k����� https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ����������������е�����k����㡣

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����331070
����֪ʶ�㣺 ����

����˼·��
    1. ջ�����Բ�ͨ�������Ǹо��߼�Ӧ��û�����⣩
    2. ˫ָ�루������ͨ��������

�ύ��¼��
    1. û�п��� k ���������ȵ����
    2. ����С�ı߽�������Լ��ֶ�����������
*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
        // ջ
        /*
        ListNode * cur = pListHead;
        stack<ListNode*> sl;
        
        while (cur) {
            sl.push(cur);
            cur = cur->next;
        }

        k--;
        while (k--) {
            sl.pop();
        }

        return sl.top();*/

        ListNode * pre = pListHead;
        ListNode * nxt = pListHead;
        //���� nxt �� k-1 ��
        while (k && nxt) {
            nxt = nxt->next;
            k--;
        }

        // ��� k > 0��˵�� k �� ������������ NULL
        if (k > 0) {
            return NULL;
        }

        // ����������ָ��һ�������ߣ��� nxt �����ʱ��pre ��ָ������ k ��
        while (nxt) {
            nxt = nxt->next;
            pre = pre->next;
        }
        
        return pre;
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

    Solution().FindKthToTail(&l1, 6);

}