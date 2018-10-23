/*
��ΪS���������� https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
�������:
��Ӧÿ�����԰����������������С���������

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����95401

����˼·��
    ��β˫ָ���ƶ�
    �˻���С��������û���ã���Ϊ����Խ����������˻�ԽС

�ύ��¼��
    1. ��ջ���
        return vector<int> {array[lo], array[hi]}; ������ôд���ⲻ�� Python

*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> ret;
        int lo = 0, hi = array.size() - 1;

        int tmp;
        while (hi - lo > 1) {
            tmp = array[lo] + array[hi];
            if (tmp < sum)
                lo++;
            else if (tmp > sum)
                hi--;
            else
            {
                ret.push_back(array[lo]);
                ret.push_back(array[hi]);
                break;
            }
        }
        // �Ľ�
        /*
        while (hi - lo > 1) {
            if (array[lo] + array[hi] == sum)
            {
                ret.push_back(array[lo]);
                ret.push_back(array[hi]);
                break;
            }
            while (lo < hi && array[lo] + array[hi] < sum) lo++;
            while (lo < hi && array[lo] + array[hi] > sum) hi--;
        }
        */

        return ret;
        //return vector<int> {array[lo], array[hi]};
    }
};

void solve()
{
    vector<int> a{ 1,2,3,4,5 };
    auto ret = Solution().FindNumbersWithSum(a, 7);
}