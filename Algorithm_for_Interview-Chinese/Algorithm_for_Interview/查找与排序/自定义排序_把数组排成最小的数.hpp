/*
�������ų���С���� https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����112505
����֪ʶ�㣺 ����

����˼·��

�ύ��¼��
    1. д�����ڵıȽϺ��������� ��̬��Ա (static)
        bool cmp(int &l, int &r)  -> static bool cmp(int &l, int &r)

*/
#pragma once

#include "../all.h"

class Solution {
public:

    // ��Ҫ��̬����
    static bool cmp(int &l, int &r) {
        string ll = to_string(l) + to_string(r);
        string rr = to_string(r) + to_string(l);

        return ll < rr;
    }

    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        stringstream ss;

        for (auto i : numbers) 
            ss << to_string(i);

        return ss.str();
    }
};

void solve()
{
    vector<int> ns{ 34,3,332 };
    sort(ns.begin(), ns.end(), Solution::cmp);

    for (auto i : ns) {
        print(i);
    }
}
