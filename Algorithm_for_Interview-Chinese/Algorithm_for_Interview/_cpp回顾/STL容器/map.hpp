/*
�ֵ� map

ע�⣺
    map û������ͨ�� value �� key �ķ���
        һ�ֵ�Ȼ�ǵ�����������
        ���滹������һ�ָ��߼��ķ�����ͨ�� lambda ���ʽ����
*/
#pragma once

#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    void test() {
        // ���캯��
        map<int, int> m1{ { 1,2 },{ 2,3 },{ 3,4 } };
        map<int, int> m2(m1.begin(), m1.end());
        map<int, int> m3(m2);

        m3[1] = 3;  // ����
        m3[4] = 5;  // ���룬�޷���ֵ
        
        // ���룬������������ʧ�ܣ�ע���� [] ������
        pair<map<int, int>::iterator, bool> ret;
        ret = m3.insert(pair<int, int>(1, 4));
        if (ret.second == false)
            cout << "exist" << endl;

        // hint ���루�����ã�
        auto it = m3.begin();
        it = m3.insert(it, pair<int, int>(6, 7));  // Ч�ʲ�����ߵ�
        // �����Ч���йأ�������
        // > ���� stack overflow �ϵ����ʣ�
        //      c++ - Does it matter that the insert hint place which is close the final place is before or after the final place? - Stack Overflow https://stackoverflow.com/questions/49653112/does-it-matter-that-the-insert-hint-place-which-is-close-the-final-place-is-befo

        // C++11 ���﷨������
        ret = m3.emplace(5, 6);  // ����ɹ�
        ret = m3.emplace(1, 4);  // ����ʧ�ܣ�key=1 ������
        it = m3.emplace_hint(it, 8, 9);  // hint ����

        // ɾ�� by key
        m3.erase(3);  

        // ���� by key
        it = m3.find(7);  // ɾ�� by iterator
        if (it == m3.end())
            m3[7] = 77;

        // ���� by value
        // ������������
        // lambda ����
        int v = 77;
        it = find_if(m3.begin(), m3.end(),
            [v](const std::map<int, int>::value_type item) {
            return item.second == v;
        });
        if (it != m3.end()) {
            int k = (*it).first;
            cout << k << endl; // 7
        }
        // ���⣬���к�������ķ�ʽ
        // > C++ map ����value��key - CSDN���� https://blog.csdn.net/flyfish1986/article/details/72833001

        for (auto& i : m3)
            cout << i.first << ": " << i.second << endl;
    }

    
};

int solve() {
    Solution().test();

    return 0;
}