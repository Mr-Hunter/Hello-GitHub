/*
ƽ������� https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ�ö��������жϸö������Ƿ���ƽ���������

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����89960

����˼·��
    ƽ����������
    �ݹ�

    �������Ƽ����ᵽ�˸ý����ڵ����⣺�����������к����Ե����⣬���ж��ϲ����ʱ�򣬻����ظ������²��㣬�����˲���Ҫ�Ŀ�������
    ���������������� + ��֦�������൱���
    
    ע�⣺��֦������ Math.abs(leftHeight - rightHeight) > 1 ? -1 : 1 + Math.max(leftHeight, rightHeight);

    public class Solution {
        public boolean IsBalanced_Solution(TreeNode root) {
            return getDepth(root) != -1;
        }

        private int getDepth(TreeNode root) {
            if (root == null) {
                return 0;
            }
            int leftHeight = getDepth(root.left);
            if (leftHeight == -1) {
                return -1;
            }
            int rightHeight = getDepth(root.right);
            if (rightHeight == -1) {
                return -1;
            }
            return Math.abs(leftHeight - rightHeight) > 1 ? -1 : 1 + Math.max(leftHeight, rightHeight);
        }
    }
�ύ��¼��
    1. pass
    
*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL) return true;
        
        return abs(depthTree(pRoot->left) - depthTree(pRoot->right)) <= 1 
            && IsBalanced_Solution(pRoot->left) 
            && IsBalanced_Solution(pRoot->right);
    }

    int depthTree(TreeNode* pRoot) {
        if (pRoot == NULL) return 0;

        return 1 + max(depthTree(pRoot->left), depthTree(pRoot->right));
    }
};

void solve() {

}