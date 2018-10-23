/*
��
���������ֹ����ѵķ�ʽ��
    1. ʹ�á����ȶ��С�
    2. ʹ��`make_heap` (todo)
*/
#pragma once

#include "../../all.h"
#include <queue>
using namespace std;

class Solution {
public:
    struct node {
        int v1;
        int v2;
        //bool operator () (const node &l, const node &r) {
        //    return l.v1 != r.v1 ? l.v1 < r.v1 : l.v2 < r.v2;
        //}
    };

    // �º����Ƚ��� - ����
    struct cmp {
        bool operator () (int l, int r) {
            return l > r;
        }
    };
    // �Զ���Ƚϣ��ȱȽ�Ԫ�� 1���ٱȽ�Ԫ�� 2
    struct cmp2 {
        bool operator () (const node &l, const node &r) {
            return l.v1 != r.v1 ? l.v1 < r.v1 : l.v2 < r.v2;
        }
    };

    void test() {
        // vector ת���ȶ���
        //   ����Ǵ�ͳ ACM �����ݶ�ȡ��ʽ�����Բ�����ô�����ڶ�ȡ����ʱ��ֱ�Ӵ������ȶ���
        //   ����� LeetCode �ķ�ʽ�����ֱ�ӽ��ܵ���һ�� vec ��������ô������Ҫ�õ����ַ���
        vector<int> v1 = { 1,2,3 };
        //priority_queue<int> p1(v1);  // û��ֱ�ӽ� vec ת pri_que �Ĺ���
        priority_queue<int> p1(v1.begin(), v1.end());
        cout << p1.top() << endl;  // 3

        // �������
        p1.push(5);
        // ��ȡ��������
        auto top = p1.top();
        cout << top<< endl;  // 5
        // ������������
        p1.pop();   // û�з���ֵ���������Ҫʹ�ö��������ݣ���Ҫ�Ƚ���

        // ����ת���ȶ���
        int arr[] = { 1,2,3 };
        priority_queue<int, vector<int>, cmp> p2(arr, arr + 3); // ʹ�÷º���������С�ѣ�Ĭ������
        cout << p2.top() << endl;  // 1

        // �Զ���ṹ��
        node arr2[] = { {1, 1}, {2, 2}, {2, 4}, {2, 3}, {1, 2} };
        priority_queue<node, vector<node>, cmp2> p3(arr2, arr2 + 5);
        p3.pop();  // {2, 4}
        p3.pop();  // {2, 3}
        p3.pop();  // {2, 2}
        p3.pop();  // {1, 2}
        p3.pop();  // {1, 1}
    }

    
};

void solve() {
    Solution().test();
}