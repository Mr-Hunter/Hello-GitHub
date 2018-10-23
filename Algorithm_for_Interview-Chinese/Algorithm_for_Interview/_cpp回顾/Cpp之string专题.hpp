/*
���߱��Ժ����ϲ���� string ��ص�����

C++ ���鷳��һ���ǣ��ܶ�ʱ�� string �� char* ����ͨ��

Python �е��ַ�������ǳ����㣬
������������������ Python �г��õĲ���Ϊ��׼��������Ӧ�� C++ ����ʽ

��Ҫ������
    1. string �� char* ��ת��           - Python ��û�и�����
        (1). string ת const char*
        (2). const char* ת string
        (3). string ת char*
        (4). char* ת string
        (5). const char* ת char*
    2. string/char* �� int ��ת��       - int(str) / str(int)
    3. string/char* �ĳ���              - len(str)
    ��todo��
    4. �ַ���ƴ��
    5. trim(): ȥ����β�հ׷�
    6. split(): �ָ��ַ���

ע��㣺
    1. const char* �������ڳ�ʼ�� char*
*/
#pragma once

#include "../all.h"
#include <string>

class Solution {
public:
    void test() {
    /*1. string �� char* ��ת��*/
        //(1). string ת const char*
        string s = "abc1";
        // char* c_s = s.c_str();  // err: const char* �������ڳ�ʼ�� char*
        const char* cs = s.c_str();
        
        //(2). const char* ת string
        const char* cs2 = "abc2";
        string s2 = cs2;
        string s3(cs2);
        string s4{ cs2 };  // ����д��������Ϊ�ȼ�

        //(3). string ת char*
        string s5 = "abc3";
        int len = s.length();
        char* cs3 = new char[len + 1];
        strcpy(cs3, s.c_str());

        //(4). char* ת string
        char cs4[64] = "abc4";
        char *cs5 = new char[64]{ "abc5" };
        char cs6[] = "abc6";            // ע�⣺���� char *cs6 = "abc6"
        cout << strlen(cs6) << endl;
        string s6(cs6);
        cout << s6 << endl;
        //
        string s7{ "" };
        for (size_t i = 0; i < strlen(cs6); i++)    // char* ת string ��ֱ�۵�д��
            s7 += cs6[i];
        cout << s7 << endl;

        //(5). const char* ת char*
        // һ�ַ�����ʹ�� strcpy()
        const char* cs7 = "abc7";
        char* cs8 = new char[strlen(cs7) + 1]; // �㹻��
        strcpy(cs8, cs7);
        cout << cs8 << endl;
        // ��򵥵ķ�����Ȼ����ǿת
        char* cs9 = (char*)cs7;
        char* cs10 = (char*)"abc8";      // ��Ҳ�ǽ� const char* ת char*

    /*2. string/char* �� int ��ת��*/
        char c1[] = "123";
        string si{ c1 };
        int i1;

        // char* ת int
        i1 = atoi(c1);      // char* ת int
        // i1 = atoi(s1);   // atoi �������� string ת int

        // string ת int - C++11
        i1 = stoi(c1);  // stoi Ҳ֧�� char* ת int
        i1 = stoi(si);

        // int ת char*
        char c2[32];
        //sprintf(c2, "%d", i1);    // ��1
        //itoa(i1, c2, 10);         // ����
        _itoa(i1, c2, 10);          // ��2�����Ƽ���LeetCode ����֧�ָ÷���

        // int ת string
        si = to_string(i1);
        cout << si << endl;

    /*3. string / char* �ĳ���*/
        // char* �ĳ���
        len = strlen(cs);
        // string �ĳ���
        len = s.length();
    }

    vector<string> split(string &s, string &delim) {
        // �����ַ����Ŀ�ͷ������� delim
        vector<string> ret;

        auto lo = s.begin();
        while (true) {
            auto hi = find(lo, s.end(), ' ');
            ret.push_back(string(lo, hi));
            if (hi != s.end())
                lo += delim.length();
            else
                break;
        }

        return ret;
    }
};

void
solve()
{
    //Solution().test();
    string s{ "abcbbbabc" };
    string d{ "bbb" };
    auto it = s.find(d);
    cout << it;
    /*
    auto ret = Solution().split(s, d);
    for (auto i : ret)
        cout << i << endl;*/


}