/*
406. ��������ؽ����� - LeetCode (�й�) https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/

����������
    �����д���˳���һȺ��վ��һ�����С� ÿ������һ��������(h, k)��ʾ������h������˵���ߣ�k�����������ǰ������ߴ��ڻ����h�������� ��дһ���㷨���ؽ�������С�

    ע�⣺
        ����������1100�ˡ�

    ʾ��
        ����:
            [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

        ���:
            [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

˼·��
    ̰���㷨

    ÿ���ҳ�ʣ�ಿ����ߵģ����� k ֵ���뵽�µ�����
    > [Easy concept with Python/C++/Java Solution](https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89345/Easy-concept-with-PythonC++Java-Solution) - LeetCode ������
    
    ����Ҫ������γ��������ѧģ�͵ģ�Ψһ�ķ��������������ɣ�
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.first > p2.first  // �Ƚ���
                || (p1.first == p2.first && p1.second < p2.second);  // ������
        };
        sort(people.begin(), people.end(), cmp);

        vector<pair<int, int>> ret;
        for (auto p : people)
            ret.insert(ret.begin() + p.second, p);

        return ret;
    }
};

void
solve()
{

}
