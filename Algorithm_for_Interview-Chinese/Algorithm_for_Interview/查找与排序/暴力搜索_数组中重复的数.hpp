/*
�������ظ������� https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� 
������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ�
���ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����98747
����֪ʶ�㣺 ����

����˼·��
    ���� - ʱ��
    ˳����� - �ռ�
    
�ύ��¼��
    1. ���Ƿ���ֵ��

*/
#pragma once

#include "../all.h"

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length <= 0) return false;

        *duplication = -1;
        set<int> s;
        for (int i = 0; i < length; i++)
        {
            if (s.count(numbers[i]) > 0) {
                *duplication = numbers[i];
                break;
            } 
            s.emplace(numbers[i]);
        }

        if (*duplication == -1) return false;
        return true;
    }
};
