/*
136. Single Number https://leetcode.com/problems/single-number/description/

��Ŀ����
    ����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����106869
����֪ʶ�㣺 ����

֪ʶ�㣺
    λ����

˼·��
    ���(^) ����

    ���֪ʶ�㣺
        a ^ 0 = a
        a ^ a = 0 
        a ^ b ^ a = b

*/
#pragma once

#include "../all.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto i : nums)
            ret ^= i;
        return ret;
    }
};

void 
solve()
{

}
