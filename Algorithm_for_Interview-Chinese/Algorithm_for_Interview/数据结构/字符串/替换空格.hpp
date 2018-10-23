/*
�滻�ո� https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����539801
����֪ʶ�㣺 �ַ���

���裺����ʹ�� replace����������ԭ�ַ����Ͻ����滻�������㹻��

�ύ��¼��
    ��һ���ύʧ�ܣ�û���ֶ��� '\0'������Ϊ�������Ὣ '\0'֮����ڴ涼��Ϊ '\0'
*/

#pragma once

#include "../all.h"

class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (str == NULL || length < 0)
            return;

        int l_old = strlen(str);
        //print(l_old);
        int n_space = count(str, str + l_old, ' ');
        //print(n_space);
        int l_new = l_old + n_space * 2;
        //print(l_new);
        str[l_new] = '\0';

        int p_old = l_old-1;
        //print(str[p_old]);
        int p_new = l_new-1;
        while (p_old >= 0) {
            if (str[p_old] != ' ') {
                str[p_new--] = str[p_old--];
            }
            else {
                p_old--;
                str[p_new--] = '0';
                str[p_new--] = '2';
                str[p_new--] = '%';
            }
        }
    }
};

void solve() {
    const int length = 100;
    char cs[length] = "   ";

    Solution().replaceSpace(cs, length);
    print(cs);
}