/*
��������˳��ʹ����λ��ż��ǰ�� https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����244244
����֪ʶ�㣺 ����

����˼·��
    ԭ��������뿼˳�ƣ�ð������
    ��ֱ�������������¼��ż�������·Ž�ԭ���飬ʱ�临�Ӷ�Ӧ�ø��ͣ����ǿռ临�Ӷȸ�

�ύ��¼��
    һ��
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // �����߼�
        vector<int> odd;
        vector<int> eve;
        for (auto i : array) {
            if (i & 1)
                eve.push_back(i);
            else
                odd.push_back(i);
        }

        array.swap(odd);
        array.insert(array.begin(), eve.begin(), eve.end());
    }
};

void 
solve() {

}