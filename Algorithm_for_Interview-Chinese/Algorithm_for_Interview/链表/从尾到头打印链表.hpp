/*
��ͷ��β��ӡ���� https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����473746
����֪ʶ�㣺 ����

�ύ��¼��
    һ�ι�
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {

        deque<int> tmp;

        ListNode *p = head;
        while (p != NULL) {
            tmp.push_front(p->val);
            p = p->next;
        }

        return vector<int>(tmp.begin(), tmp.end());
    }
};

void solve() {

    //Solution().printListFromTailToHead();
}