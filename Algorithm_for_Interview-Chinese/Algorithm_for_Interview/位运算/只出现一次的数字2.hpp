/*
137. ֻ����һ�ε����� II - LeetCode (�й�) https://leetcode-cn.com/problems/single-number-ii/description/

��Ŀ��Դ��LeetCode

��Ŀ������
    ����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

    ˵����
        ����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

    ʾ�� 1:
        ����: [2,2,3,2]
        ���: 3

    ʾ�� 2:
        ����: [0,1,0,1,0,1,99]
        ���: 99

˼·��
    1. ʹ�ö���ռ�
        1) ʹ���ֵ�/map���÷���ֻ������ʱ�临�Ӷȣ��ռ临�Ӷ�Ϊ O(n)
        2) ʹ�ü��� sum(set(nums))*3 - sum(nums) = 2 * x���ռ临�Ӷ�Ϊ O(n)

    2. λ����������ʹ�ö���ռ�
        Ŀǰ��������˼·��
          1) https://leetcode.com/problems/single-number-ii/discuss/43297/Java-O(n)-easy-to-understand-solution-easily-extended-to-any-times-of-occurance
            ˼·1 �Ƚ���������������û��x���������������ֶ����������Σ�
            ��ô�������ֶ����Ʊ�ʾ�ĵ� x λ��Ӷ�Ӧ�ÿ��Ա�3���������ĳһλ���ܣ������ x ����һλ���� 1
            �÷�����ʱ�临�Ӷ�λ O(mn)������ m Ϊ�����Ƶ�λ����һ�� m=32�����Կ���ʱ�临�Ӷ�Ϊ O(n)

            ����ֻ˵��˼·��ʵ��ʵ��ʱ��Ҫ��������λ������
                1> �жϵ� i λ�Ƿ�Ϊ 1 ��i �� 0 ��ʼ��
                    if ((num >> i & 1) == 1)
                2> �õ� i λΪ 1
                    ans != 1 << i

          2) https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
            ���˼·�����ϸ�������һ���ģ�Ҳ�Ǽ�¼�������� 1 ������λ�ã����Ǹ���������λ������������������⣨�����£�

�ύ��¼��
    1. if ((num >> i & 1) == 1) д����
       if ((num << i & 1) == 1)

*/
#pragma once

#include "../all.h"

class Solution {
public:

    // ˼· 2.1
    int singleNumber(vector<int>& nums) {
        const int bit_size = 32;

        int ans = 0;
        for (auto i = 0; i < bit_size; i++) {
            int bit_sum = 0;
            for (auto num : nums) {
                if ((num >> i & 1) == 1)
                    bit_sum++;
            }
            if (bit_sum % 3 != 0)
                ans |= 1 << i;
        }
        
        return ans;
    }
};

void
solve()
{

}