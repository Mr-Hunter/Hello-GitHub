/*
�˿���˳�� https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Ρ�Ϊ�˷������,�������Ϊ��С����0��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����81754

����˼·��
    ������
    �������ڲ�ֵ�������˳�ӣ���ô�ܲ�ֵӦ���� 4
    ����� 1 �� 0��...

�ύ��¼��
    1. ���� [3,0,0,0,0] û��

*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());

        int sum = 0; // ��¼��ֵ
        int n_0 = 0; // ��¼ 0 ������
        for (int i = 0, j = 1; i < numbers.size() - 1 && j < numbers.size(); i++, j++)
        {
            if (numbers[i] == 0) {
                n_0++;
                continue;
            }
            sum += numbers[j] - numbers[i];
        }

        return sum == 4 || n_0 == 4;
    }
};

void
solve()
{

}