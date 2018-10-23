/*
�����������ĺ���������� https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����185596

����˼·��
    ��������������������С�ڸ��ڵ㣬�����������ڸ��ڵ�
    ������������һ���Ǹ��ڵ�

�ύ��¼��
    1. ���������ڴ棨�ݹ��ʱ���������ǽ���������
    2. �߽��жϣ���������  if (l >= r) return true;

*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        return isSquenceOfBST(sequence, 0, sequence.size() - 1);
    }

    // Ϊ�˱��⸴�ƣ���һ���Ӻ���
    // l, r �Ǳ�����
    bool isSquenceOfBST(vector<int> &s, int l, int r) {
        if (l >= r) return true;
        int mid;  // ָ���һ������ s[r] ����
        // ���� mid
        for (mid = l; mid < r && s[mid] < s[r]; mid++);
        // ��� mid ֮�����Ҳ���� s[r] ��˵����������������Ķ���
        bool flag = true;
        for (int i = mid; i < r; i++) {
            if (s[i] < s[r]) {
                flag = false;
                break;
            }
        }
        return flag && isSquenceOfBST(s, l, mid - 1) && isSquenceOfBST(s, mid, r-1);
    }
};

void solve()
{
    vector<int> v{ 2,4,3,6,8,7,5 };
    Solution().VerifySquenceOfBST(v);
}