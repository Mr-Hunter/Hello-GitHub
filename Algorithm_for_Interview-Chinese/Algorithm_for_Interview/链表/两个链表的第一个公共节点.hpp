/*
��������ĵ�һ��������� https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
�������������ҳ����ǵĵ�һ��������㡣

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����95850
����֪ʶ�㣺 ����

����˼·��
    �ȷֱ����һ��õ����ߵĳ��� m n����� m>n������һ����ʱָ���ƶ���������� m-n λ��
    ���������������ȳ��������ҵ�һ������λ��

�ύ��¼��

*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) return NULL;

        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        int l1 = getListLength(p1);
        int l2 = getListLength(p2);

        if (l1 > l2) {
            p1 = walkStep(p1, l1 - l2);
        }
        else {
            p2 = walkStep(p2, l2 - l1);
        }

        while (p1 != NULL) {
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }

    int getListLength(ListNode *head) {
        if (head == NULL) return 0;
        int sum = 1;
        while (head = head->next) sum++;
        return sum;
    }

    ListNode * walkStep(ListNode *head, int step) {
        while (step--) {
            head = head->next;
        }
        return head;
    }
};

void
solve()
{

}