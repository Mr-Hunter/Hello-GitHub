/*
�������ľ��� https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
���������Ķ�����������任ΪԴ�������ľ���
��������:
�������ľ����壺
Դ������
     8
   /  \
  6   10
 / \  / \
5  7 9 11
���������
     8
   /  \
  10   6
 / \  / \
11 9 7  5

����˼·��
    1. ������� + ջ ��pass��
    2. ��ǰ������������ÿ����㣬����������Ľ�����ӽ�㣬�ͽ������������ӽڵ㣬
        �����������еķ�Ҷ�ӽ��������ӽ��֮�󣬾͵õ������ľ�����������

�ύ��¼��
    1. ������־���ô���
    2. ����ı��
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        //if (pRoot->left == NULL && pRoot->right == NULL)
        //    return;
        // ��ʹ����������Ϊ NULL��Ҳ���ᱨ�����ǽ�������ָ�� NULL ��ָ��
        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};