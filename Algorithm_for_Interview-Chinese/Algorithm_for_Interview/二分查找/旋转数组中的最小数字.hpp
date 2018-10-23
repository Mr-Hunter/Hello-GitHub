/*
��ָOffer����ת�������С���� https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
LeetCode 153. Ѱ����ת���������е���Сֵ�����ظ��� https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
LeetCode 154. Ѱ����ת���������е���Сֵ II�����ظ��� https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

��Ŀ����
    ���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

    ( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��

    ���ҳ�������С��Ԫ�ء�

    �����������Ƿ�����ظ�Ԫ�أ�������ʹ�����´���

˼·��
    ���ֲ��ң����忴����
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        auto n = nums.size();
        if (n < 1) return 0;

        int lo = -1;
        int hi = n - 1;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] < nums[hi])           // ��Ϊ��� lo ����Ϊ�����䣬����� nums[hi] �Ƚ�
                hi = mid;
            else if (nums[mid] > nums[hi])
                lo = mid;
            else
                hi--;                           // �����ظ�Ԫ��
        }

        return nums[lo + 1];
    }
};


void solve() {
    vector<int> nums{ 2, 1 };
    int ret = Solution().findMin(nums);
    print(ret);
}
