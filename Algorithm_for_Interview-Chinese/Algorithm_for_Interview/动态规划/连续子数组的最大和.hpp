/*
��������������� https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2

��Ŀ��Դ����ָOffer

��Ŀ����
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
��������鿪����,���ַ�����:
    �ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
    ����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
    ����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��᲻�ᱻ������ס��(�������ĳ���������1)

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����111925
����֪ʶ�㣺 ����

����˼·��
    1. ��̬�滮�����ؼ���״̬ת��/���ƺ���
    2. DFS

�ύ��¼��
    1. ����ȫΪ��������������Գ�ʼ��С������Ϊ 0
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {

        int m = array[0];  // ����ȫΪ���������
                           // �ȫ�������Ǹ�ֵΪ����ĵ�һ����
        for (int i = 0; i < array.size(); i++)
        {
            int s = 0;
            for (int j = i; j < array.size(); j++)
            {
                s += array[j];
                m = max(m, s);
            }
        }

        return m;
    }
};

void
solve()
{

}
