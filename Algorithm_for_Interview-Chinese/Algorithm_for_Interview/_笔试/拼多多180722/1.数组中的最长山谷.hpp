/*
�����е��ɽ��
> LeetCode 845. �����е��ɽ�� https://leetcode-cn.com/problems/longest-mountain-in-array/description/
  ԭ������ɽ��������ĳ���ɽ��

ʾ����
    ���룺
        [4,3,2,5,3,1,4,8]
    �����
        5
    ˵����
        [5,3,1,4,8]

ע�⣺�������������ַ��� "[4,3,2,5,3,1,4,8]"�����Խ���ʹ�� Python��ֱ�� `A = eval(input())` ��������

    �ҵĴ����ʱ�������ûע�⵽������⣬ֻ���� 20%����һֱû�ҵ�ԭ�򣬿Ӱ�

    �κ���Ҫ �����ַ��� �����ⶼ����ʹ�� Python

���������� LeetCode �� AC �Ĵ���
*/
#pragma once

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

void
solve() 
{
    //vector<int> A;
    //int a;
    //while (cin >> a)
    //    A.push_back(a);
    vector<int> A{ 4,3,2,5,3,1,4,8 };
    int n = A.size();
    int maxN = 0;

    if (n < 3) cout << maxN;

    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j + 1 < n && A[j + 1] < A[j])    // �ĳ� A[j + 1] > A[j] ����ɽ��
            j++;
        int k = j;
        while (k + 1 < n && A[k + 1] > A[k])    // �ĳ� A[k + 1] < A[k] ����ɽ��
            k++;
        if (j > i && k > j)                     //  ע��ֻ�����»����²���ɽ��
            maxN = max(maxN, k - i + 1);
    }
    
    cout << maxN;
}

//int main() {
//
//    solve();
//    return 0;
//}

