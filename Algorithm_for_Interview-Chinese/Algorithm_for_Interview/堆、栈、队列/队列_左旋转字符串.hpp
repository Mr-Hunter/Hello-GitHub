/*
����ת�ַ��� https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ���������������һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����96578
����֪ʶ�㣺 �ַ���

˼·������
    ���û�������˫�˶��У�

    ������������һ��ʮ�����������

        str = "XYZdefabc", n = 3
        str = "XYZdefabc" + "XYZ" = "XYZdefabcXYZ"
        return str.substr(n, len)

�ύ��¼��
    1. û�п��� str = "" �����
*/
#pragma once

#include "../all.h"

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) return "";

        deque<char> d;
        for (auto i : str)
            d.emplace_back(i);

        int len = str.length();
        int move = n % len;

        stringstream ss;

        for (int i = n; i < len; i++)
            ss << d[i];
        for (int i = 0; i < n; i++)
            ss << d[i];

        return ss.str();

    }
};

void solve()
{
    string s{ "abcXYZdef" };

    string ret = Solution().LeftRotateString(s, 3);
    print(ret);
}
