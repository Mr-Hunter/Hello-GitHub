/*
imhuay/Deep_Learning_Notes_for_Interview-Chinese https://github.com/imhuay/Deep_Learning_Notes_for_Interview-Chinese/tree/master/�����澭/#1-����ͷ��-�㷨����ʦ-ʵϰ

��Ŀ��Դ������ͷ��ʵϰ���ԡ����֮��

��Ŀ������
    ������Ԫ�ػ��ֳ������֣�ʹ�����ֺ͵Ĳ���С������˳��ɱ䣻
    ������Ԫ�صĲ�ֵ
    ���� OJ ���⣬ֻ��֤�������������ܴ��� BUG��

����˼·��
    ������Եȼ��ڡ���������ȡ������Ԫ�أ�ʹ���ǵĺ���ӽ� sum/2������ sum Ϊ��������ĺ͡���

    ˼· 1��
        > ������ֳ�������ʹ�������ֵĺ͵Ĳ���С - �ƿ� https://www.tuicool.com/articles/ZF73Af
        ��ʱ���Խ�ԭ���⿴��һ����������
        ��һ����ά���� dp[i][j] ��ʾ��ǰ i ������װ����Ϊ j �ı����ܹ�װ�µ����ֵ
        ״̬ת�Ʒ��̣�
            dp[i][j] = max{dp[i-1][j-ns[i]]+ns[i], dp[i-1][j]}
        ����
            dp[i-1][j-ns[i]]+ns[i] ��ʾ�� i ��������뱳�������Σ�
            dp[i-1][j] ��ʾ�� i �����岻���뱳��������

        ����ֵ
            sum - 2 * dp[n-1][sum/2]

        ���Ϸ�����Ȼ���У������൱�˷ѿռ䣺���� j ��Ȼ������������Ȼ�������п��ܷ������

    ˼· 2��
        �������������������� N �������Ӽ� I���� 2*abs(sum(N)/2 - sum(I))��ȡ��С����Ϊ����ֵ
        > ../�����Ӻ���/�����Ӽ�

        ע��㣺
        - sum(N)/2 �����Ǹ������������м���Ӧ�ô�Ϊ double ����
        - ��󷵻�ֵ�� 2 * abs(sum(N)/2 - sum(I))�������� abs(sum(N)/2 - sum(I))

*/
#pragma once

#include "../all.h"

class Solution {
public:
    // ˼· 2
    int getMaxDiff(vector<int>& nums) {

        vector<vector<int>> subsets;
        getAllSubsets(nums, subsets);

        double sum = getSum(nums);
        double diff = INF;
        for (auto sub : subsets) {
            diff = min(diff, abs(sum / 2 - getSum(sub)));
        }
        
        return diff * 2;
    }

    double getSum(vector<int>& nums) {
        double sum = 0;
        for (auto i : nums)
            sum += i;
        return sum;
    }

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
    vector<int> nums{ 2,5,6,10 };

    auto ret = Solution().getMaxDiff(nums);

    print(ret);
}