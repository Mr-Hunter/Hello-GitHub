/*
���ظ��ַ�����Ӵ� - LeetCode (�й�) https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/

��Ŀ��Դ��LeetCode

��Ŀ������
    ����һ���ַ������ҳ��������ظ��ַ�����Ӵ��ĳ��ȡ�

    ʾ����

    ���� "abcabcbb" ��û���ظ��ַ�����Ӵ��� "abc" ����ô���Ⱦ���3��
    ���� "bbbbb" ������Ӵ����� "b" ��������1��
    ���� "pwwkew" ����Ӵ��� "wke" ��������3��
    
    ��ע��𰸱�����һ���Ӵ���"pwke" �� ������  �������Ӵ���

    ʱ�临�Ӷȣ� O(n)

����˼·��
    ʹ��һ�� map ��¼������ÿ���ַ���λ�ã�һ��������¼��ǰ��Ӵ�����
    �ؼ�����θ��µ�ǰ�Ӵ���ʼĩλ��

    ÿ������һ���ظ��ַ�ʱ����**��ǰ**���ظ��ִ����� m = j - i������ j Ϊ�ظ��ַ���ǰ��λ�ã�i Ϊ���ַ���һ�γ��ֵ�λ��
    ���û���ظ�����ô j++
    e.g.
        i  j
        abcabcbb  -> m = j-i = 3-0 = 3
         i  j
        abcabcbb  -> m = j-i = 4-1 = 3
            i j
        abcabcbb  -> m = j-i = 6-4 = 2

�ύ��¼��
    1. ���� abba δͨ����Ԥ�ڣ�2��ʵ�ʣ�3 = 3 - 0 (a)
        �޸ģ�ֻ�е� dict[s[j]] > i ʱ���Ÿ��� i = dict[s[j]];
        �����У���Ϊ dict['a'] < i_b ���ԣ������� i
    2. �޸ĺ� AC

*/
#pragma once
#include "../all.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 1)
            return 0;

        const int pad = -1;
        vector<int> dict(256, pad);
        int m = 0;
        int i = -1, j = 0; // ��ʼʱ j-i = 1

        while (j < s.length()) {
            if (dict[s[j]] > i) // �ؼ�
                i = dict[s[j]];
            dict[s[j]] = j;
            m = max(m, j - i);
            j++;
        }

        return m;
    }

    // �ο���
    int lengthOfLongestSubstring_�ο�(string s) {
        if (s.length() < 1)
            return 0;
        
        vector<int> dict(256, -1);
        int maxLen = 0;
        int start = -1;

        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }

        return maxLen;
    }
};


void
solve()
{

}
