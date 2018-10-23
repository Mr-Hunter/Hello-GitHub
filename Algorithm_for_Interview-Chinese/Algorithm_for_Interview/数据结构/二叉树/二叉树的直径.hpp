/*
543. ��������ֱ�� - LeetCode (�й�) https://leetcode-cn.com/problems/diameter-of-binary-tree/description/

����������

    ����һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ������·�����ܴ�������㡣

    ʾ�� :
        ����������
            1
           / \
          2   3
         / \
        4   5
        ���� 3, ���ĳ�����·�� [4,2,1,3] ���� [5,2,1,3]��

        ע�⣺�����֮���·��������������֮��ߵ���Ŀ��ʾ��

˼·��
    ����������·�� = ����������������

    ���εݹ�
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int d = depth(root->left) + depth(root->right);
        return max({ d, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right) });
    }

    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max({ depth(root->left), depth(root->right) });
    }
};

void
solve()
{

}