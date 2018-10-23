/*
538. �Ѷ���������ת��Ϊ�ۼ��� https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/

��Ŀ������
    ����һ��������������Binary Search Tree��������ת����Ϊ�ۼ�����Greater Tree)��ʹ��ÿ���ڵ��ֵ��ԭ���Ľڵ�ֵ�������д������Ľڵ�ֵ֮�͡�

    ���磺
        ����: ����������:
                      5
                    /   \
                   2     13
        ���: ת��Ϊ�ۼ���:
                     18
                    /   \
                  20     13

˼·��
    �ݹ飺�������������
        ������
        �ۼ�
        ������
*/
#pragma once

#include "../binary_tree.hpp"

class Solution {
public:
    int sum;

    TreeNode * convertBST(TreeNode* root) {
        if (root == NULL) return root;
        sum = 0;
        convert(root);
        return root;
    }

    void convert(TreeNode* cur) {
        if (cur == NULL) return;
        convert(cur->right);
        cur->val += sum;
        //sum += cur->val;  // err
        sum = cur->val;     // cur->val �Ѿ��ۼӹ���
        convert(cur->left);
    }
};

void
solve()
{

}