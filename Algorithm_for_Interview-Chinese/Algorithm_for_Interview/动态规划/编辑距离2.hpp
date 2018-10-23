/*
583. �����ַ�����ɾ������ - LeetCode (�й�) https://leetcode-cn.com/problems/delete-operation-for-two-strings/description/

����������

    ������������ word1 �� word2���ҵ�ʹ�� word1 �� word2 ��ͬ�������С������ÿ������ɾ������һ���ַ����е�һ���ַ���
    ʾ�� 1:
        ����: "sea", "eat"
        ���: 2
        ����: ��һ����"sea"��Ϊ"ea"���ڶ�����"eat"��Ϊ"ea"
    ˵��:
        �������ʵĳ��Ȳ�����500��
        ���������е��ַ�ֻ����Сд��ĸ��

˼·��
    ��̬�滮���ο� "./�༭����.hpp" �ĵ��ƹ�ʽ��
        dp[i][j] = 0                                                i=0, j=0
                 = i                                                i>0, j=0
                 = j                                                i=0, j>0
                 = dp[i-1][j-1]                                     A[i-1] == B[j-1]
                 = min{dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1}  A[i-1] != B[j-1]
    �����������һ�����
        ��Ϊ��
        dp[i][j] = min{dp[i-1][j]+1,  // ɾ�� word1 �е�һ���ַ�
                       dp[i][j-1]+1,  // ɾ�� word2 �е�һ���ַ�
                       dp[i-1][j-1]+2 // ͬʱɾ�� word1 �� word2 �е�һ���ַ���������Ҫ�������
                       }  A[i-1] != B[j-1]

    ��һ�ֶ�̬˼·�ǡ�����������С���û�����룬���Բο��ٷ�����
    > �ٷ����� (5) https://leetcode.com/problems/delete-operation-for-two-strings/solution/
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (size_t i = 1; i <= m; i++)
            dp[i][0] = i;
        for (size_t i = 1; i <= n; i++)
            dp[0][i] = i;
        for (size_t i = 1; i <= m; i++)
            for (size_t j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2 });
            }

        return dp[m][n];
    }
};

void
solve()
{

}