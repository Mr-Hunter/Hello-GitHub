/*
����λ�õ���

��Ŀ��Դ����Ϊ����
*/
#pragma once

#include "../all.h"

//#include "all.h"
//#include "test.hpp"
//#include "�����Ӻ���/�����Ӽ����ݹ飩.hpp"
//#include "��̬�滮/������Ӵ�.hpp"
//#include "utils/λ����.hpp"

#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int _main() {

    stack<string> tmp;
    string s;
    getline(cin, s);
    auto it = s.begin();
    while (it != s.end()) {
        auto to = find(it, s.end(), ' ');
        tmp.push(string(it, to));
        if (to != s.end())
            it = to + 1;
        else
            break;
    }

    stringstream ss;
    while (!tmp.empty()) {
        ss << tmp.top() << ' ';
        tmp.pop();
    }

    cout << ss.str();

    system("PAUSE");
    return 0;
}