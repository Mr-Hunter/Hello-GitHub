/*
��ֵ�������η� https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

��Ŀ��Դ����ָOffer

��Ŀ������
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����204325

֪ʶ�㣺
    ����������

����˼·
    �����ⷨ������������ - O(n)
    ���������� - O(logN)
*/
#pragma once

#include "../all.h"

class Solution {
public:
    double Power(double base, int exponent) {
        // O(n) �ⷨ
        /*if (base == 0.0)
            return 0;
        if (exponent == 0)
            return 1;

        double ret = 1;
        if (exponent > 0)
            while (exponent--) {
                ret *= base;
            }
        else (exponent < 0)
            while (exponent++)
                ret /= base;

        return ret;*/

        // O(logN) �򵥿�����
        int p = abs(exponent);
        double ret = 1.0;
        while (p != 0) {
            if (p & 1)
                ret *= base;
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1 / ret : ret;
    }       
};

void solve() {

}

