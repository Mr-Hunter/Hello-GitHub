/*
��һ - LeetCode (�й�) https://leetcode-cn.com/problems/plus-one/description/

��Ŀ��Դ��LeetCode

��Ŀ������
    ����һ���Ǹ�������ɵķǿ����飬�ڸ����Ļ����ϼ�һ������һ���µ����顣

    ���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�

    ����Լ���������� 0 ֮�⣬��������������㿪ͷ��

    ʾ�� 1:

    ����: [1,2,3]
    ���: [1,2,4]
    ����: ���������ʾ���� 123��
    ʾ�� 2:

    ����: [4,3,2,1]
    ���: [4,3,2,2]
    ����: ���������ʾ���� 4321��

����˼·��
    1. ���ν�λ

�ύ��¼��

*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret(digits);
        for (int i = ret.size() - 1; i >= 0; i--) {
            if (ret[i] < 9) {
                ret[i]++;
                return ret;
            }
            ret[i] = 0;
        }
        ret.insert(ret.begin(), 1);

        return ret;
    }
};

void
solve()
{

}

