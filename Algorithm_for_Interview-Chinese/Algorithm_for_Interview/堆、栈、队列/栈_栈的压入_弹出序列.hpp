/*
ջ��ѹ�롢�������� https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����161504
����֪ʶ�㣺 ջ

����˼·��
    1. �Ƚ� pushV ������ �� popV �Ƿ���ȣ����ȣ���ɾ�� popV �ĵ�һ��Ԫ�أ��� pushV �еĸ�Ԫ�أ����űȽ�
        ������������Ȼ���������ǣ�ջ�����
    2. ��ժ��������������һ��������ջ������ѹջ˳���Ƚ���һ������ջ�У������� 1��
        Ȼ���ж�ջ��Ԫ���ǲ��ǳ�ջ˳��ĵ�һ��Ԫ�أ�������4������Ȼ1��4���������Ǽ���ѹջ��
        ֱ������Ժ�ʼ��ջ����ջһ��Ԫ�أ��򽫳�ջ˳������ƶ�һλ��
        ֱ������ȣ�����ѭ����ѹջ˳�������ɣ�
        �������ջ����Ϊ�գ�˵���������в��Ǹ�ջ�ĵ���˳��

�ύ��¼��
*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        /*vector<int> tmp(pushV.rbegin(), pushV.rend());

        if (pushV.size() == 2) {
            return is_vec_same(tmp, popV);
        }

        if (!is_vec_same(tmp, popV)) {
            int top = popV[0];
            popV.erase(popV.begin());
            auto it = find(pushV.begin(), pushV.end(), top);
            pushV.erase(it);
            return IsPopOrder(pushV, popV);
        }
        else
            return true;*/

        if (pushV.empty()) return false;

        stack<int> tmp;
        int j = 0;
        for (int i = 0; i < pushV.size(); i++) {
            tmp.push(pushV[i]);

            while (!tmp.empty() && tmp.top() == popV[j]) {
                tmp.pop();
                j++;
            }
        }

        return tmp.empty();
    }

    bool is_vec_same(vector<int> v1, vector<int> v2) {
        for (int i = 0; i < v1.size(); i++)
            if (v1[i] != v2[i])
                return false;
        return true;
    }
};
