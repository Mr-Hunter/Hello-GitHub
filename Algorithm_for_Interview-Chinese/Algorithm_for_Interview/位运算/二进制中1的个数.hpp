/*
��������1�ĸ��� https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����197271

˼·��
    ����

*/
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "../all.h"

class Solution {
public:
    // ����ķ���
    int NumberOf1(int n) {
        int cnt = 0;

        while (n != 0) {
            cnt++;
            n = n & (n - 1);
        }

        return cnt;
    }

    // ֱ�۵ķ���
    int NumberOf1_2(int n) {
        int cnt = 0;

        while (n != 0) {
            if (n & 1) cnt += 1;
            n >>= 1;
        }

        return cnt;
    }
};

void 
solve() {
    bitset<8> ns{ 127 };  // �������� ����
    print(ns.count());
}
