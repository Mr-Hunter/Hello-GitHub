/*
�������������Ӳ�����ʲô���ӵĲ�����
��������ǿ�����ǣ���Ҳû�и��߼��ļ��ɡ�

ʱ�临�Ӷ� O(��n)

ע��㣺
    1. �ҵ���С���ӣ���һ�������ӿ���ֱ����������Ա���������Ӧ���� ��n
    2. ѭ������ `i <= ��n` ����д�� `i*i <= n`
    3. ��� n ����������ƽ������ʱ С���� == ������

*/
#pragma once

#include "../all.h"

class Solution {
public:
    void getAllPositiveDivisor(int num, vector<vector<int>>& ret) {
        for (int i = 1; i*i <= num; i++) {
            if (num % i == 0) {
                ret.emplace_back(i);
                if (num / i != i)
                    ret.emplace_back(num / i);
            }
        }
    }
};

void
solve()
{

}
