/*
쳲��������� https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
n<=39

ʾ��
    0 1 2 3 5

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����283159

�ύ��¼��
    ���Լ�д�����˸������飬�ռ临�Ӷ�Ϊ O(n)
    ������������ O(1) ��д��

*/
#pragma once

#include "../all.h"

class Solution {
public:
    int Fibonacci(int n) {
        // �ռ临�Ӷ� O(n)
        long nums[40];
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i < n; i++)
            nums[i] = nums[i - 1] + nums[i - 2];
        //return nums[n];

        // �ռ临�Ӷ� O(1)
        int f = 0;
        int g = 1;
        while (n--) {
            g = g + f;
            f = g - f;
        }
        return f;
    }
};

void solve() {
    int ret;
    ret = Solution().Fibonacci(0);
    print(ret);
    ret = Solution().Fibonacci(1);
    print(ret);
    ret = Solution().Fibonacci(2);
    print(ret);
    ret = Solution().Fibonacci(3);
    print(ret);

}