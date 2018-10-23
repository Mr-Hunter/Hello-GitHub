/*
ջ stack
    ջ�������ǡ��Ƚ������

    ���ڲ���ʹ��˫�˶��� deque ʵ�ֵģ������˲��ֽӿ�
*/
#pragma once

#include <list>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    void test() {
        stack<int> s1;
        s1.push(1);
        s1.push(2);
        s1.push(3);

        // pop() û�з���ֵ����������Ҫʹ�õ�����ֵ����Ҫ�Ƚ���
        auto top_val = s1.top();  // 3
        s1.pop();

        // ����ʹ�� deque ������ stack
        deque<int> d1 = { 1,2,3 };
        stack<int> s2(d1);

        s2.push(4);
        top_val = s2.top();  // 4
        s2.pop();  // {1,2,3}

    }

};

int solve() {
    Solution().test();

    return 0;
}