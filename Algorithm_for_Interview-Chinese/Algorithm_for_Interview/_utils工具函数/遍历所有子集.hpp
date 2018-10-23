/*
��������������Ҫ����������Ӽ�
    ���磺../��̬�滮/��������ʹ��֮����С.hpp

˼·��
    ���õݹ�/�������Է���ı��������Ӽ�
    > c++ - Finding all the subsets of a set - Stack Overflow https://stackoverflow.com/questions/728972/finding-all-the-subsets-of-a-set

    getAllSubsets()��
    1. For `{1}`, the subsets is `{{}, {1}}`
    2. For `{1, 2}`, add 2 to each subset of `{{}, {1}}` to get `{{2}, {1,2}}`.
       Then union them to get all subsets is `{{}, {1}, {2}, {1, 2}}`
    3. Repeat until reach `n`

    ���������Ҫ�󣬿����ڻ�ȡ�����Ӽ����ٲ�����������ѭ���м����֦
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void getAllSubsets(vector<int>& vs, vector<vector<int>>& subsets) {
        subsets.push_back({});

        vector<vector<int>> tmp;
        for (auto i : vs) {
            for (auto sub : subsets) {
                sub.push_back(i);
                tmp.push_back(sub);
            }
            for (auto sub : tmp) {
                subsets.push_back(sub);
            }
            tmp.clear();
        }
    }
};

void
solve()
{
    vector<vector<int>> subsets;
    vector<int> vs{ 1,2,3 };

    Solution s;

    s.getAllSubsets(vs, subsets);
    for (auto i : subsets) {
        cout << "{ ";
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << '}';
        cout << endl;
    }
}