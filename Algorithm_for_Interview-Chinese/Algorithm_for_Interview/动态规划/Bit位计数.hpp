/*
LeetCode 338. Bitλ���� https://leetcode-cn.com/problems/counting-bits/description/

��Ŀ������
    ����һ���Ǹ����� num�� ���ڷ�Χ 0 �� i �� num �е�ÿ������ i ����������������е�1����Ŀ����������Ϊ���鷵�ء�
    ʾ����
        ������� num = 5 ��Ӧ�÷��� [0,1,1,2,1,2].

Ҫ��
    ������ʱ��O(n)����һ�α����������ռ临�Ӷ�ΪO(n)
    ��ʹ�����Ե����ú���

˼·��
    ��̬�滮
*/
#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);   // ע�⣺& ����������ȼ����� +
        }

        return dp;
    }

    // pass
    vector<int> countBits_my(int num) {
        vector<int> dp(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            if (i & 1)  // i Ϊ����
                dp[i] = dp[i - 1] + 1;
            else {      // i Ϊż��
                int j = 0;
                int k = i - 1;
                while (k & 1) {
                    k >>= 1;
                    j++;
                }
                dp[i] = dp[i - 1] - j + 1;
            }
        }

        return dp;
    }
};