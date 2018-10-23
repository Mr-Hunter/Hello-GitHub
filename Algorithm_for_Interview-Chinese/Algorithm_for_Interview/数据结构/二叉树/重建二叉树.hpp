/*
�ؽ������� https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����313348

�ύ��¼��
    �ο����������� Java ����
    ��˼·����д�������ݹ�̫�����ˣ�

�Ľ����飺
    ����ʹ�ô������ķ�ʽ�����½� vector��������Ҫ��дһ���Ӻ��������ǵ�����ʱû��Ч�����⣬��û��ô��

�ʼǣ�
    ���� 
        ǰ�� {1,2,4,7,3,5,6,8}�� ���� {4,7,2,1,5,3,8,6}
    ��ǰ�������ǰ���ؽ�������ʱ��ÿ��ֻ��עǰ��ĵ�һ��ֵ�������ָ�����
        Ҳ����ֻ��עǰ���е� 1 ������ֳ� {4,7,2} �� {5,3,8,6}
    ʵ���ϣ�{4,7,2} �� {5,3,8,6} Ҳ��ǰ�򻮷ֳ��� {2,4,7} �� {3,5,6,8}
        �ֻ��ʱ����һ��������Ҫ�����Ǵ����ع�ʱ����Ҫ֪����һ���ݹ������
        ������� {4,7,2} �� {2,4,7}���� {5,3,8,6} �� {3,5,6,8}
        ���Ƿֱ������������� ǰ�� �� ���� �������
    ������ݹ��˼·�����ʶ���
*/

#pragma once


#include "../all.h"

class Solution {
public:
    TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() <= 0)
            return NULL;

        TreeNode* root = new TreeNode{ pre[0] };
        for (auto i = 0; i < vin.size(); i++) {
            if (vin[i] == pre[0]) {
                root->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + 1 + i), vector<int>(vin.begin(), vin.begin() + i));
                root->right = reConstructBinaryTree(vector<int>(pre.begin() + 1 + i, pre.end()), vector<int>(vin.begin() + 1 + i, vin.end()));
            }
        }
        return root;
    }
};