/*
���������������г��ֵĴ��� https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
ͳ��һ�����������������г��ֵĴ�����

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����108012
����֪ʶ�㣺 ����

����˼·��
    ���ֲ��������½�

�ύ��¼
    1. pass

*/
#pragma once

#include "../all.h"

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        return upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k);
    }
};

void
solve()
{
    vector<int> data{ 1,2,2,2,3 };
    int ret = Solution().GetNumberOfK(data, 2);
    print(ret);
}