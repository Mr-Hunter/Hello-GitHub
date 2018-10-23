/*
�������´�ӡ������ https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����169323

����˼·
    �������Ĳ��������������ȣ�����

�ύ��¼
    1. ��ѭ���������һ�θ��ڵ㣬ѭ�����ּ���һ��
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;

        //ret.push_back(root->val);
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            ret.push_back(cur->val);

            if (cur->left != NULL)
                q.push(cur->left);
            if (cur->right != NULL)
                q.push(cur->right);
        }

        return ret;
    }
    //stack<TreeNode*> s;
    queue<TreeNode*> q;
};

void 
solve()
{

}