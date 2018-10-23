/*
�ַ��������� https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
    ����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
��������:
    ����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����180797
����֪ʶ�㣺 �ַ���

����˼·��
    DFS �ҳ���������
    ����

�ύ��¼��

*/
#pragma once

#include "../all.h"

class Solution {
    string s;
    string tmp;
    int strlen;
    vector<string> ret;
    vector<int> book;

    void dfs(int step) {
        if (step == strlen) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i<strlen; i++) {
            if (book[i] != 1) {
                tmp[step] = s[i];
                book[i] = 1;
                dfs(step + 1);
                book[i] = 0;
            }

        }
    }

public:
    vector<string> Permutation(string str) {
        s = str;
        strlen = str.length();
        tmp.resize(strlen, '\0');
        book.resize(strlen, 0);
        dfs(0);
        return ret;
    }

};

void solve() {
    Solution().Permutation("abc");
}