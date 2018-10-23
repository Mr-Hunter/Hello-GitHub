/*
��֤���������� - LeetCode (�й�) https://leetcode-cn.com/problems/validate-binary-search-tree/description/

��Ŀ��Դ��LeetCode

��Ŀ������
    ����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

    һ��������������������������

    �ڵ��������ֻ����С�ڵ�ǰ�ڵ������
    �ڵ��������ֻ�������ڵ�ǰ�ڵ������
    �������������������������Ҳ�Ƕ�����������

    ʾ�� 1:
    ����:
      2
     / \
    1   3
    ���: true

    ʾ�� 2:
    ����:
        5
       / \
      1   4
     / \
    3   6
    ���: false
    ����: ����Ϊ: [5,1,4,null,null,3,6]��
    ���ڵ��ֵΪ 5 �����������ӽڵ�ֵΪ 4 ��

����˼·��
    �ݹ�

�ύ��¼��
    1. ��ǰ�ڵ�Ҫ����/С������������/������
    ���ж���������ʱ��Ҫͬʱ�������ǵĸ��ڵ㣬��Ϊ��������ֵ/��Сֵ

*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) return true;
        if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};