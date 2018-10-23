/*
5. ������Ӵ� - LeetCode (�й�) https://leetcode-cn.com/problems/longest-palindromic-substring/description/

����������
    ����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ1000��

    ʾ�� 1��
        ����: "babad"
        ���: "bab"
        ע��: "aba"Ҳ��һ����Ч�𰸡�
    ʾ�� 2��
        ����: "cbbd"
        ���: "bb"

˼·��
    ��̬�滮
    ���ֻ����������Ӵ��ĳ��ȣ�����ƹ�ʽ�� "./�����������.hpp" ��ȫ��ͬ

    ������Ҫ����������Ӵ�����Ҫ���¶��� dp

    ���壺
        dp[i][j] := �Ӵ� s[i..j] �Ƿ��ǻ����Ӵ�
    ��ʼ��
        dp[i][j] = true     i=j
                 = false    other
    ���ƹ�ʽ��
        dp[i][j] = s[i]==s[j]                   j-i=1
                 = s[i]==s[j]&dp[i+1][j-1]      j-i>1

    ������˶�̬�滮����һ���ѵ�����α�������һ���Ӵ�
*/
#pragma once

#include "../all.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int max_len = 1;    //����������Ӵ�����
        int start = 0;      //����������Ӵ����

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        //for (int j = 1; j < n; j++)         // �Ӵ�����λ��
        //    for (int i = 0; i < j; i++) {   // �Ӵ���ʼλ��
        // ���ϣ�ѭ����ʽ����ȷ�ģ����� "./�����������" �в���
        // ���£������������ж���ȷ
        for (int j = 1; j < n; j++)             // �Ӵ�����λ��
            for (int i = j - 1; i >= 0; i--) {  // �Ӵ���ʼλ��
                if (j - i < 2)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);

                // �����Ӵ�
                if (dp[i][j] && max_len < (j - i + 1)) {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        return s.substr(start, max_len);
    }
};

void
solve()
{
    string s{ "abbaabccba" };
    auto ret = Solution().longestPalindrome(s);
    print(ret);
}