/*
����min������ջ https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����134302
����֪ʶ�㣺 ջ

����˼·��
    ������ջ������ STL �������ɣ��ؼ��� min()
    �洢���е� min ҲҪ�õ�һ��ջ

�ύ��¼��
    1. top() �� min() ������ return ...
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void push(int value) {
        s1.push(value);
        if (s_min.empty()) {
            s_min.push(value);
        }
        if (value <= s_min.top()) {
            s_min.push(value);
        }
    }
    void pop() {
        int tmp = s1.top();
        s1.pop();
        if (tmp == s_min.top())
            s_min.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s_min.top();
    }

    stack<int> s1;
    stack<int> s_min;
};

void solve()
{

}
