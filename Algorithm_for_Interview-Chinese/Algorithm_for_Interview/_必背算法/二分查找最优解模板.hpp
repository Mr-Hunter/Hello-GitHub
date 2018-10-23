/*
���ֲ������Ž��ģ�壺
    ��һ�������£����������� C �����/С�� x

ע��㣺
    - ��ʼ�����½磺
        �����ֵʱ�����½� lo ��ʼ��Ϊһ������Ŀ��н⣻�Ͻ��ʼ��Ϊһ�������������Ľ�
        ����Сֵʱ����֮
    - һ���������Ž�������ṩ����Ҫ����Ҫ�ڷ���ʱ����
        - ���ֵ�á���ȡ���� floor(ret * 1000) / 1000 ������λ���ȣ�floor: �ذ�
        - ��Сֵ�á���ȡ���� ceil(ret * 1000) / 1000  ������λ���ȣ�ceil:  �컨��

*/
#pragma once

#include "../all.h"

/*�� 1��
����� Ŀ��ֵ v(>0) ����Сֵ����ȷ�� 3 λС��
*/
double min_bigger(double v) {
    // ��ʼ�����½�
    double lo = v - EPSILON, hi = INF;

    for (size_t i = 0; i < 100; i++) {          // 100 ��ѭ���Ѿ��ܴﵽ�൱�ľ���
        double mid = lo + (hi - lo) / 2.0;
        if (mid <= v)
            lo = mid;
        else
            hi = mid;
    }

    // ��Ϊ hi �ڽ�ռ��У�hi �ش��� v�������Է��� hi
    return ceil(hi * 1000) / 1000; // ��λ����
}


/*�� 2��POJ No.1064
    �� N �����ӣ����ȷֱ�Ϊ Li��������������и�� K ��������ͬ�����ӣ����� K �����ӵ���󳤶ȡ��𰸱��� 2 λС����
*/
class Solution {
public:
    double max_length(vector<double> ls, int k) {
        double lo = 0, hi = INF;

        for (size_t i = 0; i < 100; i++) {
            double mid = lo + (hi - lo) / 2;

            if (C(ls, mid, k))
                lo = mid;
            else
                hi = mid;
        }

        // ��Ϊ lo �ڽ�ռ��У����Է��� lo
        return floor(lo * 100) / 100;
    }
private:
    bool C(vector<double> ls, double mid, double k) {
        int n = 0;
        for (size_t i = 0; i < ls.size(); i++) {
            n += ls[i] / mid;
        }

        return n >= k; 
        // n >= k ˵�����мӴ�Ŀռ䣬���Ե� C ���� true ʱ��lo = mid
    }
};

void
solve()
{
    auto ret = min_bigger(3.14);
    print(ret);

    vector<double> ls{ 8.02, 7.43, 4.57, 5.39 };
    int k = 11;
    ret = Solution().max_length(ls, k);
    print(ret);
}