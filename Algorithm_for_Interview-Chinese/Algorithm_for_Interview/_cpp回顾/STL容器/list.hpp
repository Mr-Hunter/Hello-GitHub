/*
�����ò�����
    1. ǰ��
    2. β��
    3. ָ��λ�ò���
    4. ����
    5. ɾ��
    6. �Ƴ�ȫ��ĳ��ֵ

�����ʹ��Ƶ�ʲ���

ע�⣺
    ����ĵ�������֧�������ȡ���� `l.begin() + 1` ���ֲ���
*/
#pragma once

#include "../../all.h"
#include <list>

using namespace std;

class Solution {
public:
    void test() {
        list<int> l1{ 1,2,3,4,5 };

        // ǰ��
        l1.push_front(0);
        // ��ȡ��һ��Ԫ��
        auto top = l1.front();
        cout << top << endl;        // 0
        // ������һ��Ԫ��
        l1.pop_front();
        cout << l1.front() << endl; // 1

        // β��
        l1.push_back(6);
        // ��ȡ���һ��Ԫ��
        auto back = l1.back();
        cout << back << endl;       // 6
        // �������һ��Ԫ��
        l1.pop_back();
        cout << l1.back() << endl;  // 5

        // ɾ��
        auto ret = find(l1.begin(), l1.end(), 3);
        cout << *ret << endl;
        l1.erase(ret);
        ret = find(l1.begin(), l1.end(), 3);
        if (ret == l1.end())
            cout << "have erase 3" << endl;

        // �Ƴ�ĳ��ֵ����ȫ���Ƴ��������ֵ�����ڣ��޷���ֵ
        ret = find(l1.begin(), l1.end(), 5);
        cout << *ret << endl;
        l1.push_back(5);    // �����һ�� 5
        l1.push_back(5);    // �����һ�� 5
        cout << l1.size() << endl;  // 6
        l1.remove(5);       // �Ƴ����� 5
        cout << l1.size() << endl;  // 3
        ret = find(l1.begin(), l1.end(), 5);
        if (ret == l1.end())
            cout << "have remove all 5" << endl;

        // ���� - �� 4 �ֲ���
        l1.insert(l1.begin(), 3);       // 1. �ڿ�ͷ���� 3
        l1.insert(l1.begin(), 5, 3);    // 2. �ڿ�ͷ���� 5 �� 3
        l1.insert(l1.begin(), l1.begin(), l1.end());    // 3. ��ָ��λ�ò���һ����Χ
        l1.insert(l1.begin(), { 1,2,3 });               // 4. ��ָ��λ�ò���һ����ʼ���б�

        // ���
        l1.clear();
    }

    
};

int solve() {

    Solution().test();

    return 0;
}