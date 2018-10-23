/*
�������к�Ϊĳһֵ��·�� https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����167478

����˼·��
    ������� DFS, �ݹ�

�ύ��¼��
    1. �ݹ��������ʼ�������⣻
        ע��·���յ���Ҷ�ڵ㣬�������ӽڵ�

*/
#pragma once

#include "../all.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> trace;

    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        if (root)
            dfs(root, expectNumber);
        return ret;
    }

    void dfs(TreeNode* cur, int n) {
        trace.push_back(cur->val);
        // ��������
        if (!cur->left && !cur->right) {
            if (cur->val == n)
                ret.push_back(trace);  // ret �������� vector<int>�����Իᴫ�븱��
                                       // ����� Java �Ļ���������Ҫ�ֶ� new һ����ǰ·���ĸ���
        }
        if (cur->left)
            dfs(cur->left, n - cur->val);
        if (cur->right)
            dfs(cur->right, n - cur->val);
        trace.pop_back();
    }
};