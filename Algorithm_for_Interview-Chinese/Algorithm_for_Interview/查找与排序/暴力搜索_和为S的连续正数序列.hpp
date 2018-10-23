/*
��ΪS�������������� https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100�����������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!
�������:
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����102416

˼·������
    1. ��������
    2. �Ż�������������������
        a. ���ݹ�ʽ�ҳ��м�ֵ
        b. ˫ָ���ƶ�
        ��Ϊ�о������ֵ���󣬾Ͳ����

�ύ��¼��
    1. ������Χ�������� 3 û��ͨ��
        �޸� i < sum / 2  ->  i < (sum+1) / 2

*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ret;

        for(int i = 1; i < (sum+1) / 2; i++)
        {
            for (int j = i + 1; j < (sum + 1) / 2 + 1; j++)
            {
                if (getSum(i, j) == sum)
                    ret.push_back(getVec(i, j));
            }
        }

        return ret;
    }

    vector<int> getVec(int m, int n) {
        vector<int> ret;
        for (int i = m; i <= n; i++)
            ret.push_back(i);
        return ret;
    }

    int getSum(int m, int n) {
        return (m + n)*(n - m + 1) / 2;
    }
};

void
solve()
{
    Solution().FindContinuousSequence(3);
}
