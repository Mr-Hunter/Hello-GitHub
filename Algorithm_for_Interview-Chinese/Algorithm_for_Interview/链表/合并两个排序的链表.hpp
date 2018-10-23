/*
�ϲ�������������� https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����222733
����֪ʶ�㣺 ����

����˼·��
    ������ָ������˳�ƣ�
    ѭ��������������ָ�����Ϊ NULL
    ����Ȼ��һ�������ȵ�β��ע������ƴ�Ӳ���

�ύ��¼
    1. ����ͷ����������Ӧ����ѭ���ڴ������½����Ϊ NULL��
        Ӧ����ѭ�����߰ѵ�һ��λ�ô����
*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL) {
            return pHead2;
        }
        if (pHead2 == NULL) {
            return pHead1;
        }
        
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode* ret;
        if (p1->val < p2->val) {
            ret = p1;
            p1 = p1->next;
        }
        else {
            ret = p2;
            p2 = p2->next;
        }
        ListNode* cur = ret;
        while (p1 && p2) {
            
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
                cur = cur->next;
            }
            else {
                cur->next = p2;
                p2 = p2->next;
                cur = cur->next;
            }
        }

        if (p1) cur->next = p1;
        if (p2) cur->next = p2;

        return ret;
    }
};

void 
solve()
{

}