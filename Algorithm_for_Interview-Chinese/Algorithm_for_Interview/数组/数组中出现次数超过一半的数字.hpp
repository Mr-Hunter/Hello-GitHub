/*
�����г��ִ�������һ������� https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����158471
����֪ʶ�㣺 ����

����˼·:
    ��������

�ύ��¼:
    һ��

*/
#pragma once

#include "../all.h"

class Solution {
public:
    map<int, int> m;

    int MoreThanHalfNum_Solution(vector<int> numbers) {

        int l = numbers.size() / 2;

        for (auto i : numbers) {
            if (in_map(i))
                m[i] += 1;
            else
                m[i] = 1;
        }

        for (auto i : m) {
            if (i.second > l)
                return i.first;
        }

        return 0;
    }

    bool in_map(int i) {
        auto it = m.find(i);
        if (it != m.end())
            return true;
        return false;
    }
};

void solve()
{

}
{}

