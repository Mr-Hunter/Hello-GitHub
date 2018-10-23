#pragma once

// Problem - 2602 http://acm.hdu.edu.cn/showproblem.php?pid=2602
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ��ά DP
void solve() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, V;
        scanf("%d%d", &N, &V);
        vector<int> v(N+1, 0), w(N+1, 0);
        for (int i = 1; i <= N; i++)
            scanf("%d", &v[i]);
        for (int i = 1; i <= N; i++)
            scanf("%d", &w[i]);

        vector<vector<int> > dp(N + 1, vector<int>(V + 1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= V; j++) {  // ���ܴ�������Ϊ 0 ����Ʒ
                if (w[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
        printf("%d\n", dp[N][V]);
    }
}


// Problem - 2602 http://acm.hdu.edu.cn/showproblem.php?pid=2602
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// һά DP
void solve2() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, V;
        scanf("%d%d", &N, &V);
        vector<int> v(N + 1, 0), w(N + 1, 0);
        for (int i = 1; i <= N; i++)
            scanf("%d", &v[i]);
        for (int i = 1; i <= N; i++)
            scanf("%d", &w[i]);

        vector<int> dp(V + 1, 0);
        for (int i = 1; i <= N; i++) {
            for (int j = V; j >= w[i]; j--) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        printf("%d\n", dp[V]);
    }
}

// Problem - 2602 http://acm.hdu.edu.cn/showproblem.php?pid=2602
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ��������
void solve3() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, V;
        scanf("%d%d", &N, &V);
        vector<int> v(N + 1, 0), w(N + 1, 0);
        for (int i = 1; i <= N; i++)
            scanf("%d", &v[i]);
        for (int i = 1; i <= N; i++)
            scanf("%d", &w[i]);

        vector<vector<int> > dp(2, vector<int>(V + 1, 0));     // �������������������
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= V; j++) {  // ���ܴ�������Ϊ 0 ����Ʒ
                if (w[i] > j)
                    dp[i & 1][j] = dp[(i - 1) & 1][j];
                else
                    dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j - w[i]] + v[i]);
            }
        }
        printf("%d\n", dp[N & 1][V]);
    }
}

int main() {
    solve3();
    return 0;
}