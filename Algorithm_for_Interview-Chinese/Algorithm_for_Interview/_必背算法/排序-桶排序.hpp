/*
Ͱ����

˼·��
    ����ͬ�������䵽ͬһ����Ͱ���У�Ͱ������ = ���ݷ�Χ����ɢֵ������ n
    ���ȱ���һ������ m �����ݣ����ν����ݷ��ɵ����ʵġ�Ͱ���У�
    Ȼ��˳��������С�Ͱ����Ͱ�д��ڼ������ݣ���������Σ�û����������

    ʱ�临�Ӷ� O(m+n)���ʺ� n ��̫��������
    ȱ���Ƿǳ��ռ临�Ӷȸ�

˵����
    1. Ͱ�������ȶ���
    2. Ͱ�����ǳ�������������һ��,�ȿ��Ż�Ҫ�졭����������
    3. Ͱ����ǳ���,����ͬʱҲ�ǳ��Ŀռ�,����������Ŀռ��һ�������㷨
*/
#pragma once

#include "../all.h"

#define MAXN 1000

void bucketSort(int arr[], int n) {
    int b[MAXN]{ 0 };               // ��ʼ��Ϊ 0

    for (int i = 0; i < n; i++)
        b[arr[i]] += 1;

    int cnt{ 0 };
    for (int i = 0; i < MAXN; i++) {
        if (b[i] > 0) {
            for (int j = 0; j < b[i]; j++)
                arr[cnt++] = i;
        }
    }

    assert(cnt == n);
}

void
solve()
{
    int arr[]{ 22,11,2,23,21,1,1 };
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    for (auto i : arr)
        cout << i << ' ';
    cout << endl;
}