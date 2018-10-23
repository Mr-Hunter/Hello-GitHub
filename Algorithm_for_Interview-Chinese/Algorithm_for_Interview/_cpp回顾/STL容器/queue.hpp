/*
���У�
    ���е������ǡ��Ƚ��ȳ���

    ���а�������Ķ��� queue ��˫�˶��� deque

    queue ���ڲ����� deque ʵ�ֵģ�
    ��Ϊ˫�˶��а����Ķ��е����й��ܣ������Ƽ�ʹ�� deque ���� ����ʹ�� _front �� _back ������ͷ���β��

    ��Ϊ list Ҳ���� queue �Ľӿڣ����Կ���ʹ�� list ��Ϊ queue ���������
*/
#pragma once

#include <list>
#include <deque>
#include <vector>
#include <queue>
#include <iostream>
#include <memory>

using namespace std;

class Solution {
public:
    void test() {
        // ˫�˶���
        deque<int> d1 = { 1,2,3 };

        d1.push_front(0);  // {0,1,2,3}
        for (auto i : d1)
            cout << i << ' ';
        cout << endl;

        auto front_val = d1.front();
        d1.pop_front();  // {1,2,3}
        for (auto i : d1)
            cout << i << ' ';
        cout << endl;

        // һ�����
        queue<int> q1(d1);
        q1.push(12);

        // ��Ϊ list Ҳ���� queue �Ľӿڣ����Կ���ʹ�� list ��Ϊ queue ���������
        list<int> l = { 1,2,3,4,5 };
        queue<int, list<int>> q2(l);

        //queue<int> q3{ 1,2,3 };  // error��û����Ӧ�Ĺ��캯��
        //queue<int, vector<int>> q4;  // warning
    }
};

int solve() {
    Solution().test();

    return 0;
}