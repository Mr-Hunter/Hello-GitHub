/*
��Ŀ��Դ������ս������ƾ������ڶ��棩��

��Ŀ������
    �������� a1��a2��.......an���ж��Ƿ���Դ���ѡ����������ʹ���ǵĺ�ǡ��Ϊ K��

˼·��
    dfs
    ��һ����һ�� n �������ڶ���ÿ���ڵ�Ϊ (n-1)�������� (n-2)
*/
#pragma once

#include "../all.h"

#define MAX_N 21        // n <= 20
// ����
int n, k;
int arr[MAX_N];

// ���
int OK = 0;             // ����Ƿ��н�
int book[MAX_N];        // �����Щ���ֱ��õ���

// int sum;
void dfs(int sum, int step) {       // ��ǰ�ͣ���ǰ״̬
    // �ݹ��˳�����
    if (step == n || sum == k) {    // step �� 0 ��ʼ
        if (sum == k)
            OK = 1;
        return;
    }

    // ������һ��״̬
    for (int i = step; i < n; i++) {
        if (sum + arr[i] > k) continue;     // ��֦
        book[i] = 1;                        // �޸ı��
        //sum += arr[i];
        dfs(sum + arr[i], i + 1);
        if (OK) return;                     // ��ֹ�����޸�״̬
        //sum -= arr[i];
        book[i] = 0;                        // ��ԭ��ǡ������ݣ�ע�⣺��ʱ����Ҫ��ԭ���
    }
}

void solve() {

    while (cin >> n >> k) {
        OK = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            book[i] = 0;        // ��ʼ��Ϊ 0
        }

        dfs(0, 0);
        if (OK) {
            cout << "Yes: ";
            for (int i = 0; i < n; i++)
                if (book[i]) cout << arr[i] << ' ';
            cout << endl;
        }
        else cout << "No\n";
    }
}
