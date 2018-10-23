/*
�����л�����ڽ�� https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
һ�������а����������ҳ�������Ļ�����ڽ�㡣

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����78895
����֪ʶ�㣺 ����

����˼·:
    1. ���� set �洢�߹���λ�ã���Ҫ����Ŀռ�
    2. ���������ƶ��ٶȲ�ͬ��ָ�룬ͬʱǰ���������ܻ�������
        ����ʱ����ָ��ȣ���ָ������� k Ȧ
        ��ʱ��������һ��ָ������ָ������ͷ����������ͬ���ƶ�
        �������ٴ�����ʱ����ָλ�ü�Ϊ�������
        ����Ҫ����ռ䣬����ʱ������һЩ�����ӶȲ���

�ύ��¼��
    1. ˼·1 pass
    2. 

*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * EntryNodeOfLoop_1(ListNode* pHead)
    {
        ListNode* p = pHead;
        if (p == NULL) return pHead;

        ListNode* ret = NULL;
        set<ListNode*> s;
        while (p) {
            if (s.count(p) > 0) {
                ret = p;
                break;
            }
            s.emplace(p);
            p = p->next;
        }

        return ret;
    }

    ListNode * EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* ret = NULL;
        if (pHead == NULL) return ret;

        ListNode* slow = pHead;
        ListNode* fast = pHead;
        while (fast != NULL && fast->next != NULL)
        {   
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = pHead;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                ret = slow;
                break;
            }
        }
        
        return ret;
    }
};
