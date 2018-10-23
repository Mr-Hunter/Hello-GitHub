/*
����������� https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����73915

����˼·��
    ���ĵݹ鶨��

�ύ��¼��
    
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL) return 0;

        return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
    }
};

void solve()
{
    TreeNode t1{ 1 };
    TreeNode t2{ 2 };
    TreeNode t3{ 3 };
    TreeNode t4{ 4 };

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;

    int ret = Solution().TreeDepth(&t1);
    print(ret);
}
