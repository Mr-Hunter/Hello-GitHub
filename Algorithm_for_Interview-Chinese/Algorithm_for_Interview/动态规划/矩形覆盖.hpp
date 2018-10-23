/*
���θ��� https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����148824

����˼·
    ��̬�滮
    �ؼ����ҵ����ƹ�ʽ����ϧû�ҳ������븴���ˣ�
    ʵ���ϻ���쳲���������
        f(0) = 0 �������㣬�������ۣ�
        f(1) = 1
        f(2) = 2
        f(n) = f(n-1) + f(n-2)
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int rectCover(int number) {
        // f(0) = 0
        // f(1) = 1
        // f(2) = 2
        if (number == 0)
            return 0;

        int pre = 1;
        int nxt = 2;
        int tmp;
        for (int i = 2; i <= number; i++) {
            tmp = nxt + pre;
            pre = tmp - pre;
            nxt = tmp;
        }

        return pre;
    }
};

void 
solve() {

}