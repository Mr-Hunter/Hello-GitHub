/*
LeetCode 190. �ߵ�������λ https://leetcode-cn.com/problems/reverse-bits/description/

��Ŀ������
    �ߵ������� 32 λ�޷��������Ķ�����λ��

    ʾ��:
        ����: 43261596
        ���: 964176192
        ����: 43261596 �Ķ����Ʊ�ʾ��ʽΪ 00000010100101000001111010011100 ��
        ���� 964176192��������Ʊ�ʾ��ʽΪ 00111001011110000010100101000000 ��
*/
#pragma once

#include "../all.h"

class Solution {
public:

    // Ӳ���� �ĵݹ���ʽ
    uint32_t reverseBits(uint32_t n) {
        unsigned s = 8 * sizeof(n);
        uint32_t mask = ~0;
        while ((s >>= 1) > 0) {
            mask ^= mask << s;
            n = ((n >> s) & mask) | ((n << s) & (~mask));
        }
        return n;
    }

    // Ӳ����
    uint32_t reverseBits_2(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};