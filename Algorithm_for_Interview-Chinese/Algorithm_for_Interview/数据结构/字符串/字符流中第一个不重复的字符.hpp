/*
�ַ����е�һ�����ظ����ַ� https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
�������:
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����55599
����֪ʶ�㣺 �ַ���

����˼·��
    list<pair<char, int>>

    ʹ�� map ��Ч�ʸ��ߣ����� map ���ܱ���˳����Ϣ������ʹ��һ�� char[] ������֪�� str ��

�ύ��¼��
    1. �ظ�����

*/
#pragma once

#include "../all.h"

class Solution
{
public:

    list<pair<char, int>> tmp;
    //Insert one char from stringstream
    void Insert(char ch)
    {
        //pair<char, int> ci{ ch, 1 };
        //tmp.emplace_back(ci);

        auto it = tmp.begin();
        while (it != tmp.end()) {
            if (it->first == ch)
            {
                it->second++;
                return;
            }
            it++;
        }
        if (it == tmp.end()) {
            pair<char, int> ci{ ch, 1 };
            tmp.emplace_back(ci);
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        auto it = tmp.begin();
        while (it != tmp.end()) {
            if (it->second == 1)
                return it->first;
            it++;
        }
        return '#';
    }

};

void 
solve()
{

}