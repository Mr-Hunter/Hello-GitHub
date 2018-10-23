/*
���ַ���ת�������� https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0

��������:
    ����һ���ַ���,����������ĸ����,����Ϊ��
�������:
    ����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0

ʾ��1
����
    +2147483647
    1a33

���
    2147483647
    0

����˼·��
    int t = str[p] - '0';
    n = n*10 + t;

    ���ִ���������
        û�п��������ţ�͵������Ƚϼ�
        
�ύ��¼��

    1. tmp >= 0 && tmp <= 9 д���� ||


*/
#pragma once
#include "../all.h"

class Solution {
public:
    int StrToInt(string str) {
        int len = str.size();
        if (len <= 0) return 0;

        int p = 0;
        while (str[p] == ' ') p++;

        bool pos = true;
        if (str[p] == '+') {
            p++;
        }
        else if (str[p] == '-') {
            pos = false;
            p++;
        }

        int n = 0;
        while (p < len) {
            int tmp = str[p] - '0';
            if (tmp >= 0 && tmp <= 9) {
                n = n * 10 + tmp;
                p++;
            }
            else {
                return 0;
            }
        }

        return pos? n : -n;
    }
};

void solve() {
    string str{ "  123  " };

    int ret = Solution().StrToInt(str);
    print(ret);
}
