/*
260. ֻ����һ�ε����� III https://leetcode.com/problems/single-number-iii/description/
������ֻ����һ�ε����� https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ������
    ����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�

    ʾ�� :
        ����: [1,2,1,3,2,5]
        ���: [3,5]

    ע�⣺
        ��������˳�򲢲���Ҫ��������������ӣ� [5, 3] Ҳ����ȷ�𰸡�
        ����㷨Ӧ�þ�������ʱ�临�Ӷȡ����ܷ��ʹ�ó����ռ临�Ӷ���ʵ�֣�

˼·��
    1. �����ų���Ҫ����ķ�����ʱ�临�Ӷ�Ҫ�󲻷�

    2. ����Կռ临�Ӷ�û��Ҫ����ô��򵥵�������Ȼ�������ֵ�/map

    3. ���Ҫ��ռ临�Ӷ�Ϊ O(1)����ô��Ҫ���õ�λ��������ʣ�
        a ^ a = 0
        a ^ 0 = a
        a ^ b ^ a = b

        �ȿ��Ǽ򵥵���������������ֻ��һ��������һ�Σ���ô���������������ʣ������׾����ҵ�������
        ���ǣ���������������ν�ԭ���黮�֣�ʹ a �� b �ֱ����ڲ�ͬ������

        ��Ϊ a != b������ a ^ b != 0��Ҳ����˵ a ^ b �Ķ������б���һλΪ 1��
        ������� ^ �����ʣ�����һλ�ϣ�a �� b �ز���ͬ
        ���ǿ��Ը�����һ�������������飬�Ա�֤ a �� b ���ڲ�ͬ������

�ύ��¼��
    1. ���ɵ� n λΪ 1 ������Ӧ����
        int x = 1 << (n-1)��������
        int x = 1 << n;
    2. == �����ȼ����� &������
        if (i & x != 0)��Ӧ��д�� 
        if ((i & x) != 0)������ֱ��
        if (i & x)
    3. С�Ľ�
        ������ת�ͣ�����ֱ�ӷ���
            return {a, b}; ������Ҫ
            return vector<int>{a, b};
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // ��� a^b ��ֵ
        int c = 0;
        for (auto i : nums)
            c ^= i;

        // �ҳ� c �Ķ������������һ��Ϊ 1 ��λ��
        int offset = 0;
        for (int i = 0; i<8 * sizeof(int); i++) {
            if (c & (1 << i))
                break;
            offset++;
        }
        int a = 0, b = 0;
        for (auto i : nums) {
            if (i & (1 << offset))
                a ^= i;
            else
                b ^= i;
        }

        //return vector<int>{a, b};
        return { a, b };  // // �Զ�ת��
    }

    // ţ�����Ľӿ�
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        int cor = 0;
        for (auto i : data)
            cor ^= i;

        int n1 = 1;
        int tmp = cor;
        while (tmp) {
            if (tmp & 1) break;  // �ж���ż�ĳ��ò���������Ŀ�����ж����һλ�Ƿ�Ϊ 1
            n1++;
            tmp >>= 1;
        }

        tmp = 1;
        tmp <<= n1 - 1;
        *num1 = *num2 = 0;  // ��ֹ num1 �� num2 �ĳ�ֵ��Ϊ 0
        for (auto i : data) {
            if (i & tmp)
                *num1 ^= i;
            else
                *num2 ^= i;
        }
    }
};

void 
solve()
{   
    for (auto i : vector<int>{1, 2})
        print(i);

    vector<int> a{ 1, 2, 1, 3, 2, 5 };
    vector<int> ret = Solution().singleNumber(a);

    for (auto i : ret)
        print(i);

    if (3 & 5)
        print("test");
}