/*
������������˫������ https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����115280

����˼·��
    ��������Ĺ������޸�ָ��

�ύ��¼��
    1. ��һ�εݹ�ʧ�ܣ�������������

*/
#pragma once

#include "../all.h"

class Solution {
public:
    TreeNode * pre;  // ��¼��һ���ڵ�
    TreeNode * ret;  // ��¼��������ĵ�һ���ڵ�

    TreeNode * Convert(TreeNode* pRootOfTree) {
        // C++ С�ӣ�Ĭ�ϳ�ʼ����Ϊ NULL
        pre = NULL;
        ret = NULL;
        subCovert(pRootOfTree);
        return ret;
    }
    
    // �������
    void subCovert(TreeNode* node) {
        if (!node) return;

        subCovert(node->left);
        // �޸�ָ����߼�
        if (pre == NULL) {  // ������������ĵ�һ��λ�ã�������ͷ
            pre = node;
            ret = node;
        }
        else {
            pre->right = node;
            node->left = pre;
            pre = node;
        }
        subCovert(node->right);
    }
};
