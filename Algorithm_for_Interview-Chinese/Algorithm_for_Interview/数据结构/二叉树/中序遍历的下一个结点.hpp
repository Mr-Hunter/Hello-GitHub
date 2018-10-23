/*
����������һ����� https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����71769

����˼·��
    ��������Ĺ��̣���ͬ���������
    1.������Ϊ�գ��򷵻ؿգ�
    2.�ڵ��Һ��Ӵ��ڣ�������һ��ָ��Ӹýڵ���Һ��ӳ�����һֱ����ָ�����ӽ���ָ���ҵ���Ҷ�ӽڵ㼴Ϊ��һ���ڵ㣻
    3.����ýڵ����丸�ڵ�����ӣ��򷵻ظ��ڵ㣻����������ϱ����丸�ڵ�ĸ��ڵ㣬�ظ�֮ǰ���жϣ����ؽ����
    

�ύ��¼��
    1. ��� 3 ��������

*/
#pragma once

#include "../all.h"

class Solution {
public:
    TreeLinkNode * GetNext(TreeLinkNode* pNode)
    {   
        if (pNode == NULL)
            return pNode;

        if (pNode->right != NULL) {
            auto p = pNode->right;
            while (p->left != NULL)
                p = p->left;
            return p;
        }

        auto c = pNode;     // ��ǰ�ӽڵ�
        auto p = c->next;   // ��ǰ�ӽڵ�ĸ��ڵ�
        while (p != NULL)   // ���ڵ�ĸ��ڵ�Ϊ NULL
        {
            if (p->left == c)
                return p;
            c = p;          // ��ǰ�ӽڵ�ָ�򸸽ڵ�
            p = p->next;    // ���ڵ�ָ����һ�����ڵ�
        }

        return NULL;
    }
};

void
solve()
{

}