#pragma once

/*
LeetCode 838. �ƶ���ŵ https://leetcode-cn.com/problems/push-dominoes/description/

���� 180831 ���Եڶ���

�����ԭʼ�������ҷֱ����һ�� "L" �� "R"����ô�������� 4 �ֿ���
'R......R' => 'RRRRRRRR'
'L......L' => 'LLLLLLLL'
'L......R' => 'L......R'
'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'

ref: https://leetcode.com/problems/push-dominoes/discuss/132332/C++JavaPython-Two-Pointers
*/

#include "../../all.h"

class Solution {
public:
    string pushDominoes(string d) {
        string s = "L" + d + "R";
        string ret = "";

        int lo = 0, hi = 1;
        for (; hi < s.length(); hi++) {
            if (s[hi] == '.')
                continue;

            if (lo > 0)         // ע����һ������
                ret += s[lo];

            int delta = hi - lo - 1;
            if (s[lo] == s[hi])
                ret += string(delta, s[lo]);  // string ��һ�ֹ��캯������ s[lo] Ϊÿ���ַ������ɳ���Ϊ h_l ���ַ���
            else if (s[lo] == 'L' && s[hi] == 'R')
                ret += string(delta, '.');
            else if (s[lo] == 'R' && s[hi] == 'L')
                ret += string(delta / 2, 'R') + string(delta & 1, '.') + string(delta / 2, 'L');

            lo = hi;
        }

        return ret;
    }

};

void solve()
{
    string d{ ".L.R...LR..L.." };
    auto ret = Solution().pushDominoes(d);
    print(ret);
}