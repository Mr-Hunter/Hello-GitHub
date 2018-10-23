/*
��̬��̨�� https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ������
    һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
    �����������һ��n����̨���ܹ��ж�����������

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����169212

����˼·��
    ��̬�滮
    f(n) = f(n-1) + f(n-2) + .. + f(1) + 1
    f(1) = 1
    f(2) = 2
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int jumpFloorII(int number) {
        // ʹ��һ����������
        /*int tmp[1024];

        tmp[0] = 1;
        tmp[1] = 1;
        int sum = tmp[0] + tmp[1];
        for (int i = 2; i <= number; i++)
        {
            tmp[i] = sum;
            sum += tmp[i];
        }

        return tmp[number];*/

        // ���Բ��ø�������
        int f_0 = 1;
        int f_1 = 1;

        int sum = f_0 + f_1;
        for (int i = 2; i <= number; i++) {
            f_1 = sum;
            sum += f_1;
        }

        return sum;
    }
};

void
solve()
{

}