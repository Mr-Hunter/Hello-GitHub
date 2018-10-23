/*
��������������� - LeetCode (�й�) https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/

��Ŀ��Դ��LeetCode

��Ŀ������
    ����һ���������������������� ������

����˼·��
    �ݹ飺O(n) ʱ�� O(n) �ռ�
    ������O(n) ʱ�� O(n) �ռ�
    Morris traversal ��������O(n) ʱ�� O(1) �ռ�

    ref: Clear C++ solutions --- iterative, recursive and Morris traversal (3 different solutions!) - LeetCode Discuss 
    https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/Clear-C++-solutions-iterative-recursive-and-Morris-traversal-(3-different-solutions!)

    ���� Morris ��������ϸ���ͣ�
        Morris Traversal�����������������ǵݹ飬����ջ��O(1)�ռ䣩 - AnnieKim - ����԰ 
        https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html

�ύ��¼��
    1. ������߼���Ӧ��ʱ root ��Ϊ��ʱ������ݹ�
        ���鲻Ҫֱ��д if(root) �� if(!root)��
        ��д�� if (root != NULL) �� if(root == NULL)

*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root != NULL)
            inorderTraversal(root, ret);
        return ret;
    }

    void inorderTraversal(TreeNode* root, vector<int>& ret) {
        if (root->left != NULL)
            inorderTraversal(root->left, ret);
        ret.push_back(root->val);
        if (root->right != NULL)
            inorderTraversal(root->right, ret);
    }
};