/*
�������㷨

����˵����
- �� 3^20 = 9^10 = 81^5 (= 81*81^4) = 81*6561^2 = 81*43046721
- ѭ������ = `bin(20)`��λ�� = `len(10100)` = 5
*/
#include "../all.h"

double quickPow(double base, int p) {
    double ret = 1.0;
    int q = abs(p);
    while (q > 0) {
        if (q & 1)          // ���ָ��Ϊ������һ�������ϳ� 2 ������һ�λ���������2/2 = 1
            ret *= base;    // 81^5=(1*81)*81^4
        base *= base;       // 3^20=(3*3)^(20/2)
        q >>= 1;            // �� 2
    }
    return p > 0 ? ret : 1 / ret;
}

void
solve()
{
    print(quickPow(5, 2));  // 25
}