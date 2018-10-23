/*
��1+2+3+...+n https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����84691

����˼·��
    1. �ݹ�
        �ؼ���������ý��������������� && �Ķ�·����
    2. ���ƿ�����
    3. ���� sizeof �����

�ύ��¼��
    pass
*/
#pragma once

#include "../all.h"

class Solution {
public:
    // ˼· 1
    int Sum_Solution(int n) {
        int sum = n;
        (n - 1) && (sum += Sum_Solution(n - 1));

        return sum;
    }

    // ˼· 2 - ������
#define f(x) ((((x) & 1) << 31) >> 31)
    int Sum_Solution_2(int n) {
        int a = n, b = n + 1, s = 0;
        //����32�Ρ���
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;

        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;

        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;

        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        return s >> 1;
    }

    // ˼· 3 - ���� sizeof �����
    int Sum_Solution(int n) {
        bool a[n][n + 1];
        return sizeof(a) >> 1;
    }
};

void solve()
{

}