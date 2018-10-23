/*
��̨�� https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����218636

����˼·��
    ���� n ��̨�׵ķ����� = ���� (n-1) ��̨�׵ķ����� + ���� (n-2) ��̨�׵ķ�����
    ����f(n) = f(n-1) + f(n-2)  // 쳲��������У���ֻ�ǳ�ʼֵ��ͬ
    ��̬�滮
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int jumpFloor(int number) {
        int f = 1;
        int g = 2;

        number--;  // Ϊʲô����һ���������������й�
                   // ������Ĭ�ϱ�Ŵ� 0 ��ʼ�������� 1 ��ʼ
        while (number--) {
            g = g + f;
            f = g - f;
        }
        return f;
    }
};

void solve()
{

}