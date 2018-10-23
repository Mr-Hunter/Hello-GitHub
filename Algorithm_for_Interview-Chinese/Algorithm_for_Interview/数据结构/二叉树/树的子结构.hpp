/*
�����ӽṹ https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����219165

����˼·��
    1. �ȿ�����ô�ж� T1 �� T2 �Ƿ���ȫ��ͬ
        ������ڵ���ͬ���ж����ߵ��������������� -> �ݹ�

    2. �ж��ǲ����ӽṹ
        ���ҵ� T1 �и��ڵ� �� T2 һ�µĽڵ㣬�Ӹýڵ㿪ʼ 1 �Ĺ���

�ύ��¼��
    1. �ݹ�Ľ������д����
    2. д�껹���ò���һ�Ա��Լ�д������̫���ˣ�����Ĵ�����������
*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == NULL || pRoot1 == NULL)
            return false;

        return isSubTree(pRoot1, pRoot2)
            || HasSubtree(pRoot1->left, pRoot2)
            || HasSubtree(pRoot1->right, pRoot2);
    }

    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == NULL) return true;
        if (pRoot1 == NULL) return false;

        if (pRoot1->val == pRoot2->val) {
            return isSubTree(pRoot1->left, pRoot2->left)
                && isSubTree(pRoot1->right, pRoot2->right);
        }
        else
            return false;
    }
};


void
solve()
{

}