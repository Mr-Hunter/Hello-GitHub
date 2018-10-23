/*
��������ĸ��� https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ����������
��ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�

����˼·��
    ��û�������⣬����������������
    1������ÿ���ڵ㣬�磺ԭ���� A->B->C ��� A->A'->B->B'->C->C'
    2����������ʹ��A'->random = A->random->next;
    3�����������������

�ύ��¼��


*/
#pragma once

#include "../all.h"

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode * Clone(RandomListNode* pHead) {
        if (!pHead) return NULL;

        RandomListNode *cur = pHead;
        // 1. ����ÿ���ڵ㣬�磺ԭ����A->B->C ���A->A'->B->B'->C->C'
        while (cur) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        // 2. ��������ʹ��A'->random = A->random->next;
        cur = pHead;
        RandomListNode *tmp;
        while (cur) {
            tmp = cur->next;
            if (cur->random) {
                tmp->random = cur->random->next;
            }
            cur = cur->next->next;  // �������ƵĽڵ�
        }

        // 3. �������
        cur = pHead;
        RandomListNode * ret = cur->next;
        while (cur->next) {
            tmp = cur->next;
            cur->next = tmp->next;
            cur = tmp;
        }
        return ret;
    }
};

void
solve()
{

}
