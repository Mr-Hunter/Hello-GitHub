/*
����λ�������
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void bitOP() {
    /*��������Ʊ�ʾ��`1`�ĸ���*/
        vector<int> ns{0, 1, 64, 64-1, 128, 128-1};
        for (auto i : ns)
            cout << numberOfOne(i) << ' ';  // 0 1 1 6 1 7
        cout << endl;

    /*�жϵ� i λ�Ƿ�Ϊ 1 ��i �� 0 ��ʼ��*/
        int i = 4;  // ��Ϊ i �� 0 ��ʼ��������ʵ����������� 5 λ
        int n = 16; // 10000
        // �� 1���ƶ� 1
        if (n & (1 << i))
            cout << "true" << endl;
        // �� 2���ƶ� n
        if ((n >> i) & 1)
            cout << "true" << endl;

    /*�ж���ż*/
        n = 5;
        if (n & 1)
            cout << n << " ������" << endl;

    /*�򵥿�����*/
        cout << quickPow(3, 1);
    }

    /* ��������Ʊ�ʾ��`1`�ĸ���
    */
    int numberOfOne(int n) {
        int cnt = 0;
        /* ��2�����õķ�����O(m) - m Ϊ 1 �ĸ��� */
        while (n > 0) {
            cnt++;
            n &= n - 1;
            /* ˵����
                n-1 ��ᷭת������һ�� 1 ��֮���ÿһλ��
                Ȼ�� n&(n-1) ��Ѹ�λ�õ� 1 ��֮���ÿһλ���㣻
                ���ÿ��ѭ��ǡ����ȥһ�� 1 ֱ����Ϊ 0
                    n       = 100,100
                    n-1     = 100,011
                n = n&(n-1) = 100,000   cnt++
                    n-1     = 011,111
                n = n&(n-1) = 000,000   cnt++
            */
        }
        /* ��1�����淽����O(n) - n Ϊ�����Ƶĳ���
        while (n > 0) {
            if (n & 1)
                cnt++;
            n >>= 1;
        }
        */
        return cnt;
    }

    /*�򵥿�����*/
    double quickPow(double base, int p) {
        int ret = 1.0;
        int q = abs(p);
        while (q > 0) {
            if (q & 1)
                ret *= base;
            base *= base;
            q >>= 1;
        }
        return p > 0 ? ret : 1 / ret;
    }
};

void
solve()
{
    Solution().bitOP();
}