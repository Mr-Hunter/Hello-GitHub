/*
���ֲ���ģ��

ע��㣺
    - �Ƿ�����ظ�Ԫ��

ģ�� 1 - binary_search
    - û���ظ�Ԫ��ʱ��Ŀ��ֵ�����ڣ��򷵻��������������ڣ����� -1
    - �����ظ�Ԫ��ʱ��Ŀ��ֵ�����ڣ��򷵻���С�������������ڣ����� -1

ģ�� 2 - lower_bound
    - ���ش��ڡ�����Ŀ��ֵ����С��������һ�����ڡ�����Ŀ��ֵ��������

ģ�� 3 - upper_bound
    - ���ش���Ŀ��ֵ����С��������һ������Ŀ��ֵ��������
    
ע��㣺
    - 
    
*/
#pragma once

#include "../all.h"


int binary_search(vector<int>& nums, int v) {
    if (nums.size() < 1) return - 1;

    int lo = -1, hi = nums.size();

    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < v)
            lo = mid;
        else
            hi = mid;
    }

    return nums[lo + 1] == v ? lo + 1 : -1;
}


int lower_bound(vector<int>& nums, int v) {
    if (nums.size() < 1) return -1;

    int lo = -1, hi = nums.size();

    while (hi - lo > 1) {                       // �˳�ѭ��ʱ�У�lo + 1 == hi
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < v)
            lo = mid;                           // ��Ϊʼ�ս� lo �˵��������䣬����û�б�Ҫ `lo = mid + 1;`
        else
            hi = mid;                           // ���� else �У�mid ���ܾ������Ľ�������Բ��� `hi = mid - 1`
    }

    return lo + 1; // ��� binary_search��ֻ�з���ֵ��ͬ
}
/*Ϊʲô���� `lo+1`�������� `hi`�����˳�ѭ��ʱ�� lo + 1 == hi��
    ģ�忪ʼʱ�� (lo, hi) ������һ�������䣬ͨ�����϶��֣��������������ֻ�Ậ��һ��ֵ���� (lo, hi]
    ���� lo+1 �ĺ����ǣ�������� lo ����һ����
    �ڵ����Ĺ����У�hi ��ӿ������Ϊ�����䣬�� lo ʼ���ǿ����䣬
    ���� lo+1 �Եø���ͳһ��
    ��Ȼ�����������д������صģ���Ҳ����ʹ���յĽ�������� [lo, hi)����ȡ���ڸ���ϰ�ߡ�
*/


int upper_bound(vector<int>& nums, int v) {
    if (nums.size() < 1) return -1;

    int lo = -1, hi = nums.size();

    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] <= v)                     // ��� lower_bound��Ψһ��ͬ�㣺`<` -> `<=`
            lo = mid;
        else
            hi = mid;
    }

    return lo + 1;
}

void
solve()
{
    vector<int> v{ 1,2,2,3,4,6,6,6,8,9 };
    cout << v.size() << endl;       // 10

    auto ret = binary_search(v, 7);
    cout << ret << endl;            // -1

    ret = lower_bound(v, 6);
    cout << ret << endl; // 5

    ret = lower_bound(v, 7);
    cout << ret << endl; // 8

    ret = upper_bound(v, 6);
    cout << ret << endl; // 8

    ret = upper_bound(v, 7);
    cout << ret << endl; // 8
}