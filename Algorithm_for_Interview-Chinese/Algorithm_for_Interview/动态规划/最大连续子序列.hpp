/*
*/
#pragma once

#include "../all.h"

/*
����

5
1 5 -3 2 4
6
1 -2 3 4 -10 6
4
-3 -1 -2 -5

���

9
7
-1
*/
void foo() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i<n; i++)
            cin >> a[i];

        vector<int> dp(n);
        dp[0] = a[0];

        int ret = a[0];
        for (int i = 1; i < n; i++) {
            if (dp[i - 1] > 0)
                dp[i] = dp[i - 1] + a[i];
            else
                dp[i] = a[i];

            ret = max(ret, dp[i]);
        }
        cout << ret << endl;
    }
}

/*
����

5
1 5 -3 2 4
6
1 -2 3 4 -10 6
4
-3 -1 -2 -5

���

9
7
-1
*/
void foo2() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i<n; i++)
            cin >> a[i];

        int ret = INT_MIN;
        int max_cur = 0;

        for (int i = 0; i < n; i++) {
            if (max_cur > 0)
                max_cur += a[i];
            else
                max_cur = a[i];

            if (max_cur > ret)
                ret = max_cur;

            // ���Ͽ��Լ�д���������д���
            //max_cur = max(max_cur + a[i], a[i]);
            //ret = max(ret, max_cur);
        }
        cout << ret << endl;
    }
}


void foo3() {
    int n;
    while (cin >> n && n) {
        vector<int> a(n);
        for (int i = 0; i<n; i++)
            cin >> a[i];

        int ret = INT_MIN;
        int max_cur = 0;
        int beg = a[0], end = a[n-1];  // �����β
        // int beg = 0, end = n-1;     // �������

        int tmp_beg;  // ������ʱ beg
        for (int i = 0; i < n; i++) {
            if (max_cur > 0) {
                max_cur += a[i];
            }
            else {
                max_cur = a[i];
                tmp_beg = a[i];
                // tmp_beg = i;
            }

            if (max_cur > ret) {  // > ����������ǵ�һ�γ��ֵ����ͣ�>= ��Ϊ���һ�Σ�δ��֤��
                ret = max_cur;
                beg = tmp_beg;
                end = a[i];  // �����β
                // end = i;  // �������
            }
        }

        if (ret < 0) 
            printf("%d %d %d\n", 0, a[0], a[n-1]);
            // printf("%d %d %d\n", 0, 0, n-1);
        else
            printf("%d %d %d\n", ret, beg, end);
    }
}


void 
solve() {

    foo3();
}