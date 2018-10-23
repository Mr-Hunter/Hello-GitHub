/*
LeetCode 33. ������ת�������� https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/

��Ŀ������
    ���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

    ( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��

    ����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��

    ����Լ��������в������ظ���Ԫ�ء�

    ����㷨ʱ�临�Ӷȱ����� O(log n) ����

    ʾ�� 1:
        ����: nums = [4,5,6,7,0,1,2], target = 0
        ���: 4
    ʾ�� 2:
        ����: nums = [4,5,6,7,0,1,2], target = 3
        ���: -1

˼·��
    ��Ȼ����ͨ�����������ж�ֱ��һ�ζ��֣����Ǻ����׳���

    ���յ�������ͨ�����ζ��֣����ҳ���Сֵ��λ�ã�Ȼ��ȷ�� target �����䣬����һ�ζ���ȥ��
    > Ѱ����Сֵ��λ�� > LeetCode 153��154

�ύ��¼��
    �ύ�� N �βŹ����߽�����̫���׳�����
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto n = nums.size();
        if (n < 1) return -1;

        auto lo = -1;
        auto hi = n - 1;
        while (lo + 1 < hi) {
            auto mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi])
                lo = mid;
            else
                hi = mid;
        }
        if (target == nums[hi]) return hi;

        if (target > nums[hi] && target <= nums[n - 1]) {
            lo = hi;
            hi = n - 1;
        }
        else {
            lo = -1;
        }
        while (lo + 1 < hi) {
            auto mid = lo + (hi - lo) / 2;
            if (target > nums[mid])
                lo = mid;
            else
                hi = mid;
        }
        return nums[hi] == target ? hi : -1;
    }
};

void
solve()
{
    vector<int> nums{ 3,5,1 };
    Solution().search(nums, 5);
}