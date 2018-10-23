/*
��С��K���� https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����200875
����֪ʶ�㣺 ����

����˼·��
    ���ȶ���/��

�ύ��¼��
    1. û�п��� k > input.size() �����
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> ret;

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size()) return ret;

        priority_queue<int, vector<int>, greater<int>> p;
        for (auto i : input)
            p.push(i);
        while (k--) {
            ret.push_back(p.top());
            p.pop();
        }

        return ret;
    }
};

void solve() {

}