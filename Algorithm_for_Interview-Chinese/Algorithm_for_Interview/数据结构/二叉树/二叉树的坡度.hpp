/*
563. Binary Tree Tilt - LeetCode https://leetcode.com/problems/undefined/description/

��Ŀ������
    ����һ�����������������������¶ȡ�

    һ�����Ľڵ���¶ȶ��弴Ϊ���ýڵ��������Ľ��֮�ͺ����������֮�͵Ĳ�ľ���ֵ���ս��ĵ��¶���0��

    ���������¶Ⱦ��������нڵ���¶�֮�͡�

˼·��
    �ݹ�
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int findTilt(TreeNode* root) {
        if (root == NULL) return 0;
        int sum = abs(getSum(root->left) - getSum(root->right));
        return sum + findTilt(root->left) + findTilt(root->right);
    }

    int getSum(TreeNode* root) {
        if (root == NULL) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
};

void
solve()
{

}