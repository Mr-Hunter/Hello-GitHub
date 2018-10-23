/*
516. ����������� - LeetCode (�й�) https://leetcode-cn.com/problems/longest-palindromic-subsequence/description/

��Ŀ������
    ����һ���ַ���s���ҵ�������Ļ��������С����Լ���s����󳤶�Ϊ1000��

    ʾ�� 1:
        ����:
            "bbbab"
        ���:
            4
        һ�����ܵ������������Ϊ "bbbb"��

    ʾ�� 2:
        ����:
            "cbbd"
        ���:
            2
        һ�����ܵ������������Ϊ "bb"��

˼·��
    ����Ķ�̬�滮����
    �ǣ�
        dp[i][j] := �Ӵ� s[i..j] ������������еĴ�С
    ��ʼ����
        dp[i][j] = 1    i=j
                 = 0    other
    ���ƹ�ʽ��
        dp[i][j] = dp[i+1][j-1] + 2             s[i]==s[j]
                 = max(dp[i+1][j], dp[i][j-1])  other
        ��� `i+1=j` �� `s[i]=s[j]`ʱ��`dp[i][j] = dp[i+1][j-1] + 2` ��Ȼ������
        ��Ϊ `i != j` ʱ���� `dp[i][j] = 0`

    ע�⣬������������ dp ���壬����ֵӦ���� dp[1][n] ������ dp[n][n]

    ����״̬ת��֮��Ĺ�ϵ��������ж�̬�滮����Ĺؼ���Ҳ���ѵ�
        s[i]==s[j] ʱ��s[i..j] ����һ��״̬Ӧ���� s[i+1..j-1]�������� s[i+1..j+1] ����������������һ������Ȿ��Ĺؼ�
        s[i]!=s[j] ʱ��s[i..j] ����һ��״̬Ӧ���� s[i+1..j] �� s[i..j-1]�������� s[i+1..j+1] �ȵ�
    �ݲ����� DP ���Ż�
    > [Straight forward Java DP solution](https://leetcode.com/problems/longest-palindromic-subsequence/discuss/99101/Straight-forward-Java-DP-solution) - LeetCode (EN) ������

    ״̬���µ�˳��Ҳ��һ��ע��㣺
    ��ȷʾ����
        for (int i = n-1; i >= 0; i--)          // �Ӵ���ʼλ��
            for (int j = i + 1; j < n; j++) {   // �Ӵ�����λ��

        for (int j = 1; j < n; j++)             // �Ӵ�����λ��
            for (int i = j-1; i >=0; i--) {     // �Ӵ���ʼλ��

    ����ʾ����
        for (int j = 1; j < n; j++)         // �Ӵ�����λ��
            for (int i = 0; i < j; i++) {   // �Ӵ���ʼλ��
        // ���Ǹ�˳���� "./������Ӵ�.hpp" ������ȷ��

    ע�⣺
        ��Ϊ DP �Ķ���Ϊ�˱�����⣬�±곣�� 1 ��ʼ������һ���������±겻ͬ������
        Ӧ��ʹ�ñ���ʱӦ��ʹ�� `s[i-1]==s[j-1]` ������ `s[i]==s[j]`

        **��ȻҲ�����ڱ���ʱ�� DP ���±�Ҳ�������� 0 ��ʼ**
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        /* ��ֱ�۵�ѭ����ʽ
        */
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int j = 1; j < n; j++)             // �Ӵ�����λ��
            for (int i = j-1; i >=0; i--) {     // �Ӵ���ʼλ��
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max({ dp[i + 1][j], dp[i][j - 1] });
            }

        return dp[0][n - 1];

        /* �±�� 0 ��ʼ
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = n-1; i >= 0; i--)
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max({ dp[i + 1][j], dp[i][j - 1] });
            }

        return dp[0][n-1];
        */

        /*�±�� 1 ��ʼ
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            dp[i][i] = 1;
        for (int i = n; i >=1; i--)
            for (int j = i+1; j <= n; j++) {
                if (s[i-1] == s[j-1])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max({ dp[i + 1][j], dp[i][j - 1] });
            }
        
        return dp[1][n];
        */
    }
};

void
solve()
{

}