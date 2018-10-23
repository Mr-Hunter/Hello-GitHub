/*
72. �༭���� - LeetCode (�й�) https://leetcode-cn.com/problems/edit-distance/description/

����������
    ������������ word1 �� word2��������� word1 ת���� word2 ��ʹ�õ����ٲ����� ��
    ����Զ�һ�����ʽ����������ֲ�����
        ����һ���ַ�
        ɾ��һ���ַ�
        �滻һ���ַ�
    ʾ�� 1:
        ����: word1 = "horse", word2 = "ros"
        ���: 3
        ����:
            horse -> rorse (�� 'h' �滻Ϊ 'r')
            rorse -> rose (ɾ�� 'r')
            rose -> ros (ɾ�� 'e')
    ʾ�� 2:
        ����: word1 = "intention", word2 = "execution"
        ���: 5
        ����:
            intention -> inention (ɾ�� 't')
            inention -> enention (�� 'i' �滻Ϊ 'e')
            enention -> exention (�� 'n' �滻Ϊ 'x')
            exention -> exection (�� 'n' �滻Ϊ 'c')
            exection -> execution (���� 'u')

˼·��
    ��̬�滮-��������
    > Edit Distance - LeetCode https://leetcode.com/problems/edit-distance/discuss/25846/20ms-Detailed-Explained-C++-Solutions-(O(n)-Space)

    �������ַ����ֱ�Ϊ A[0..m-1] �� B[0..n-1]
    �� dp[i][j] := ��A ǰ i ���ַ��� ��B ǰ j ���ַ��ı༭����

    1. ���Ǳ߽����������һ���ַ���Ϊ�մ�����Ȼ��ʱ�� s[0..i-1] ת��Ϊ "" ������Ҫ i�� �����������

        dp[i][0] = i
        dp[0][j] = j

    2. һ����������� A���ĵ� i ���ַ��� B���ĵ� j ���ַ�
        ������֪ dp[i-1][j-1]������ A[0..i-2] ת��Ϊ B[0..j-2] ��Ҫ�Ĵ���
        1����� A[i] == B[j]����ô dp[i][j] == dp[i-1][j-1]
        2����� A[i] != B[j]���Դ�A �����ֿ��ܵĲ������Դ�B �ǶԳƵģ���
            a. �滻һ���ַ� dp[i][j] = dp[i-1][j-1] + 1
            b. ɾ��һ���ַ� dp[i][j] = dp[i-1][j] + 1����ʱӦ�� A[0..i-2] == B[0..j-1]��������Ҫ�� A ɾ���е�һ���ַ�
            c. ����һ���ַ� dp[i][j] = dp[i][j-1] + 1����ʱӦ�� A[0..i-1] == B[0..j-2]��������Ҫ�� A �����е�һ���ַ�
        
        ������ѵ����������� 3 �����

    �ɴ˿ɵõ��ƹ�ʽ��

        dp[i][j] = 0                                                i=0, j=0
                 = i                                                i>0, j=0
                 = j                                                i=0, j>0
                 = dp[i-1][j-1]                                     A[i-1] == B[j-1]
                 = min{dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1}  A[i-1] != B[j-1]

    ԭ�����ṩ�˿ռ��Ż��ķ�����ֻ��Ҫ O(m) �� O(n) �Ŀռ临�Ӷȣ����ﲻ�����롣
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
        for (size_t j = 1; j <= n; j++)
            dp[0][j] = j;
        for (size_t i = 1; i <=m; i++)
            for (size_t j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1 });
            }
        return dp[m][n];
    }
};

void
solve()
{

}