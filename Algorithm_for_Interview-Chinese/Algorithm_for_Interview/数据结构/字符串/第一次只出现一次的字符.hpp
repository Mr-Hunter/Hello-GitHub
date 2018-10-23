/*
��һ��ֻ����һ�ε��ַ� https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��

ʱ�����ƣ�1�� �ռ����ƣ�32768K �ȶ�ָ����133015
����֪ʶ�㣺 �ַ���

����˼·��
    1. ��һ�� ���� ��˳���¼�ַ�����һ�� map ��¼�����ַ������һ�γ��ֵ�λ�ã����ĳ�ַ��ڶ��γ��־ʹ�����ɾ��֮
        ��󷵻�����ͷ�ַ���λ��
    2. ���Բ�ʹ��������֮������Ҫ�ڱ���һ�� str

�ύ��¼��
    1. ˼· 1 ���ز��Կ��ԣ�ţ�Ͷ�ջ���
    2. ˼· 2 ���

*/
#pragma once

#include "../all.h"

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        //if (str == "") return -1;

        //list<char> l;
        //map<char, int> m;

        //for (int i = 0; i < str.length(); i++) {
        //    if (m.count(str[i]) == 0) {
        //        m.emplace(str[i], i);
        //        l.emplace_back(str[i]);
        //    }
        //    else {
        //        auto it = find(l.begin(), l.end(), str[i]);
        //        l.erase(it);
        //    }
        //}

        //return m[l.front()];

        map<char, int> m;
        for (int i = 0; i < str.length(); i++) {
            if (m.count(str[i]) == 0) {
                m.emplace(str[i], 1);
            }
            else {
                m[str[i]] += 1;
            }
        }
        for (int i = 0; i < str.length(); i++) {
            if (m[str[i]] == 1)
                return i;
        }
        return -1;
    }
};

void 
solve()
{
    int ret = Solution().FirstNotRepeatingChar("abcdefabcd");
    print(ret);
}