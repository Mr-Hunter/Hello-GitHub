/*
������ջʵ�ֶ��� https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����208146
����֪ʶ�㣺 ���� ջ

����˼·��
    ջ1 ���� push��ջ2 ���� pop����ջ1 �� ջ2 ���ñ���Ƚ��ȳ�
    ע�� C++ �е� pop() û�з���ֵ����Ҫ�ȼ�¼ top() �� pop()

�ύ��¼��
    ��һ���ύʧ�ܣ�
        û�п��� ջ2 ��Ϊ��ʱ���������ϰ� ջ1 �е�Ԫ�طŽ�ȥ
*/
#pragma once

#include "../all.h"

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int ret;
        if (!stack2.empty()) {
            ret = stack2.top();
            stack2.pop();
            return ret;
        }

        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int solve() {
    return 0;
}