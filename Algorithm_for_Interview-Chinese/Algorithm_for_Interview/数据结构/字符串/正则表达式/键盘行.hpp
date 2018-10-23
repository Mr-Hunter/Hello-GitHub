/*
500. ������ https://leetcode.com/problems/keyboard-row/description/

��Ŀ������
    ����һ�������б�ֻ���ؿ���ʹ���ڼ���ͬһ�е���ĸ��ӡ�����ĵ��ʡ�

    ʾ��1:
        ����: ["Hello", "Alaska", "Dad", "Peace"]
        ���: ["Alaska", "Dad"]
    ע��:
        ������ظ�ʹ�ü�����ͬһ�ַ���
        ����Լ���������ַ�����ֻ������ĸ��

˼·��
    1. ���жϵ�һ����ĸ������һ�У�Ȼ���жϺ����Ƿ������ĸ��������һ��
    2. ������ʽ

    ע�⣺��Сдת��
        char c = (char)tolower(c);
*/
#pragma once

#include "../../all.h"
#include <regex>

class Solution {
public:
    // 1.
    vector<string> findWords(vector<string>& words) {
        string s[]{ "qwertyuiop", "asdfghjkl", "zxcvbnm" };

        vector<string> ret;
        for (auto w : words) {
            // �жϵ�һ����ĸ������һ��
            int k;
            for (k = 0; k < 3; k++)
                if (s[k].find((char)tolower(w[0])) != string::npos)
                    break;

            // �жϺ����Ƿ������ĸ��������һ��
            int OK = 1;
            for (auto c : w) {
                if (s[k].find((char)tolower(c)) == string::npos)
                    OK = 0;
            }
            if (OK)
                ret.push_back(w);
        }
        return ret;
    }
    // 2. ������ʽ
    vector<string> findWords_2(vector<string>& words) {
        regex reg{ "[qwertyuiopQWERTYUIOP]*|[asdfghjklASDFGHJKL]*|[zxcvbnmZXCVBNM]*" };
        vector<string> ret;
        smatch r;   // match_results<string::const_iterator> r;
        for (auto w : words) {
            if (regex_match(w, r, reg))
                ret.push_back(w);
        }
        return ret;
    }
};
