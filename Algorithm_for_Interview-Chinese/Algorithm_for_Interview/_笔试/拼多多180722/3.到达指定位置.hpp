/*
����ָ��λ��
> Leetcode 754. �����յ����� https://leetcode-cn.com/problems/reach-a-number/description/

˼·��
    > һ���������������⣬���� - ֪�� https://www.zhihu.com/question/50790221/answer/125213696
*/
#pragma once

#include <cstdio>
#include <cmath>

int minStep(int x) {
    if (x == 0) return 0;
    if (x<0) x = -x;

    int n = sqrt(2 * x);    // �����൱��ѡ��һ���½磬 n=1 ��ʼҲ�ܹ�

    while ((n + 1)*n / 2 - x & 1 || (n + 1)*n / 2 < x)
        ++n;
    return n;
}

void
solve()
{
    int x;
    while (scanf("%d", &x))
        printf("%d\n", minStep(x));
}